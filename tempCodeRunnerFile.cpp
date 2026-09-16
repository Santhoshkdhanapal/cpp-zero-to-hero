#include <iostream>

int overflow_var= 2147483647;

int main()
{
    overflow_var = overflow_var + 1;

    std::cout << overflow_var <<std::endl;
    std::cout << sizeof(overflow_var) << std::endl;
    std::cin.get();
    return 0;
}