#include <iostream>
int large_input = 70000;
short truncated_var = (short)large_input;

int main(){
    std::cout << truncated_var << std::endl;
    std::cout << sizeof(truncated_var) << std::endl;
    std::cin.get();
    return 0;
}