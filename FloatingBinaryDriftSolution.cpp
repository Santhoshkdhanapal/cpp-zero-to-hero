#include <iostream>

double precise_var = 0.1 * 10;

int main()
{
    std::cout.precision(10);
    std::cout << precise_var << std::endl;
    std::cout << sizeof(precise_var) << std::endl;
    std::cin.get();
    return 0;
}