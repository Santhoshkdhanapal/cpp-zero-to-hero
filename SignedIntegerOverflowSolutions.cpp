#include <iostream>

unsigned int unsigned_var = 2147483647;

int main()
{
    unsigned_var = unsigned_var + 1;

    std::cout << unsigned_var <<std::endl;
    std::cout << sizeof(unsigned_var) << std::endl;
    std::cin.get();
    return 0;
}