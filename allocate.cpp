#include <iostream>
using namespace std;

int *fun() {
    int *ptr = new int;      
    *ptr = 10;         
    return ptr;           
}

int main() {
    cout << *fun();          // Access dynamically allocated value
    return 0;
}