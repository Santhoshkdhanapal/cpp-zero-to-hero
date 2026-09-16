# C++ Core Engineering: Data Types, Memory & Safe Execution

This repository documents core low-level C++ behaviors, memory models, integer arithmetic boundaries, and execution safety. It contains practical code snippets, deep dives into Undefined Behavior (UB), and reliable build configurations using GCC / MinGW-w64.

---

## 1. Signed Integer Overflow (Undefined Behavior)

In C++, signed integers (`int`, `int32_t`) rely on two's complement representation. When a calculation exceeds the maximum capacity of a signed container (`INT_MAX = 2,147,483,647`), the standard classifies the result as **Undefined Behavior (UB)**.

### The Mechanism
* **Sign Bit Flipping:** A standard 32-bit signed integer reserves the Most Significant Bit (MSB) as the sign indicator (`0` for positive, `1` for negative).
* Adding `1` to `01111111 11111111 11111111 11111111` propagates a carry bit into the MSB, producing `10000000 00000000 00000000 00000000`.
* In two's complement, this bit pattern represents `-2,147,483,648`.

### The Vulnerability: Compiler Optimization Pruning
Compilers (GCC/Clang) assume well-formed programs **never invoke undefined behavior**. If downstream logic contains an overflow check like:

```cpp
if (value + 1 < value) {
    // Abort or handle error
}

```

Under optimization flags (`-O2`, `-O3`), the compiler mathematically deduces that `value + 1 > value` must always be true because overflow is technically impossible under the ISO standard. As a result, **the compiler strips the safety check entirely**, leaving memory allocators and buffer indexes exposed to negative or corrupt bounds.

---

## 2. Code Snippets: The Error vs. Safe Mitigation

### The Bug (Unchecked Overflow)

This snippet demonstrates silent sign-bit corruption:

```cpp
#include <iostream>

int overflow_var = 2147483647;

int main()
{
    overflow_var = overflow_var + 1;

    std::cout << "Corrupted Value: " << overflow_var << std::endl; // Prints: -2147483648
    std::cout << "Data Size: " << sizeof(overflow_var) << " bytes" << std::endl;
    return 0;
}

```

---

###### Theory: Solving Signed Overflow via Unsigned Types

In C++, **signed integer overflow** is Undefined Behavior (UB), meaning the standard permits the compiler to assume it never happens and aggressively delete bounds checks or miscompile logic.

Switching to `unsigned int` solves this fundamentally at the language standard level:

1. **Well-Defined Modular Arithmetic:** Under the ISO C++ standard, unsigned arithmetic **never** produces Undefined Behavior. It is strictly defined to follow modulo arithmetic ($2^N$, where $N$ is the number of bits).
2. **Double the Positive Range:** A 32-bit `signed int` uses 1 bit for the sign, limiting positive numbers to `2,147,483,647` ($2^{31}-1$). An `unsigned int` uses all 32 bits for the magnitude, expanding the positive ceiling to `4,294,967,295` ($2^{32}-1$).
3. **No Sign-Bit Misinterpretation:** Adding `1` to `2147483647` changes the most significant bit from `0` to `1` (`0x80000000`). In a signed type, this bit makes the number negative (`-2147483648`). In an `unsigned int`, there is no sign bit; the bit simply represents the value $2^{31}$, evaluating cleanly to `2147483648`.

---

### Code

```cpp
#include <iostream>

unsigned int unsigned_var = 2147483647;

int main()
{
    unsigned_var = unsigned_var + 1;

    std::cout << unsigned_var << std::endl;
    std::cout << sizeof(unsigned_var) << std::endl;
    std::cin.get();
    return 0;
}

```

---

### Code Explanation

* `unsigned int unsigned_var = 2147483647;`
Allocates 4 bytes (32 bits) without a sign bit. The value `2147483647` in binary is:
`01111111 11111111 11111111 11111111`
* `unsigned_var = unsigned_var + 1;`
Adds `1`. The carry ripples into the 32nd bit, yielding:
`10000000 00000000 00000000 00000000`
Because the type is unsigned, the leading `1` is read as $+2,147,483,648$ rather than a negative indicator.
* `std::cout << unsigned_var << std::endl;`
Outputs `2147483648`. The value increments correctly without flipping negative or triggering undefined behavior.
* `std::cout << sizeof(unsigned_var) << std::endl;`
Outputs `4`, confirming it occupies the exact same memory footprint (4 bytes / 32 bits) as a standard `signed int`.
* `std::cin.get();`
Pauses the console window so the output stays visible until you press Enter.
```

---

## 3. Compilation & Execution Guide (GCC / MinGW-w64)

### Basic Build & Run

* **Windows (Command Prompt / PowerShell):**
```cmd
g++ main.cpp -o app.exe
.\app.exe

```


* **Linux / macOS:**
```bash
g++ main.cpp -o app
./app

```



---

## 4. Modern C++ Flags for Safety & Bug Detection

Production systems must enforce compiler warnings and runtime instrumentation to surface silent bugs before deployment.

### Recommended Production Flags

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wsign-conversion -O2 main.cpp -o app.exe

```

* `-std=c++20`: Enforces modern ISO C++ language standards.
* `-Wall -Wextra`: Activates extensive compiler diagnostic warnings for questionable code constructs.
* `-Wconversion`: Warns when data might be truncated due to implicit type conversions.
* `-Wsign-conversion`: Flags hazardous implicit conversions between signed and unsigned types.
* `-O2`: Applies standard optimization passes.

---

### Runtime Sanitizers (Catching UB Instantly)

Sanitizers inject runtime instrumentation directly into binary executables to immediately halt and log the exact line of failure when memory violations or UB occur:

```bash
g++ -std=c++20 -g -fsanitize=undefined,address main.cpp -o app_debug.exe

```

* `-g`: Generates debug symbols (enables stack traces with accurate line numbers).
* `-fsanitize=undefined` (UBSan): Halts execution immediately if signed integer overflow, null pointer dereferencing, or alignment faults occur.
* `-fsanitize=address` (ASan): Detects out-of-bounds array access, use-after-free, and stack/heap buffer overruns.

---

### Theory: Register Truncation

Register truncation occurs when a value residing in a wider data type (such as a 32-bit or 64-bit integer) is cast or assigned into a narrower storage location (such as a 16-bit `short` or 8-bit `char`).

#### Mechanical Cause

* **Bit-Discarding:** CPUs store integers across register boundaries. When moving data from a 32-bit register (e.g., `EAX`) to a 16-bit sub-register (e.g., `AX`), the processor does not scale or proportionally round the data. It copies only the least significant 16 bits (lower two bytes) and completely ignores the upper 16 bits.
* **Value Corruption:** If the value exceeds the target type's maximum capacity (for a signed 16-bit integer, $[-32768, 32767]$), the preserved lower bits produce a completely different number.
* **Bit-Pattern Breakdown:**
* Decimal value: `70000`
* 32-bit representation (Hex `0x00011170`):
`00000000 00000001 00010001 01110000`
* Truncated 16-bit slice (Hex `0x1170`):
`00010001 01110000`
* Interpreted decimal value: $4096 + 256 + 112 = 4464$



---

### Code: Register Truncation Demonstration

```cpp
#include <iostream>

int large_sensor_reading = 70000;
short truncated_var = (short)large_sensor_reading; // Drops the upper 16 bits

int main()
{
    std::cout << truncated_var << std::endl;
    std::cout << sizeof(truncated_var) << std::endl;
    std::cin.get();
    return 0;
}

```