#include <iostream>
using namespace std;

int *fun() {
    int a = 10;             
    int *ptr = &a;         
    return ptr;
}

int main() {
    cout << *fun();          // Undefined behavior
    return 0;
}