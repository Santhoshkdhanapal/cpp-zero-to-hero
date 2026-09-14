#include <iostream>

float drift_var = 0.1f * 10;

int main()
{
    std::cout.precision(10);
    std::cout << drift_var << std::endl;
    std::cout << sizeof(drift_var) << std::endl;
    std::cin.get();
    return 0;
}