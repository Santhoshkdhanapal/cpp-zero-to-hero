#include <iostream>

short truncated_var = 70000;

int main(){
    std::cout << truncated_var << std::endl;
    std::cout << sizeof(truncated_var) << std::endl;
    std::cin.get();
    return 0;
}