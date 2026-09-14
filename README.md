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

### The Solution: Branchless Clamping via Promotion

To safely saturate bounds without risking deleted `if/else` checks, promote arithmetic to a wider container (`long long` / `int64_t`) and clamp the result using `std::min`:

```cpp
#include <iostream>
#include <limits>
#include <algorithm>

long long raw_input = 2147483647LL + 1LL;
int safe_var = std::min(raw_input, static_cast<long long>(std::numeric_limits<int>::max()));

int main()
{
    std::cout << "Saturated Safe Value: " << safe_var << std::endl; // Caps at 2147483647
    std::cout << "Data Size: " << sizeof(safe_var) << " bytes" << std::endl;
    return 0;
}

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

