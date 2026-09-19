#include <iostream>
using namespace std;

int *fun() {
    int *ptr = new int;
    *ptr = 10;
    return ptr;
}

int main() {
    int *ptr = fun();       
    cout << *ptr;      
    delete ptr;             // Deallocate memory
    ptr = NULL;  
    cout << *ptr;           // Set pointer to NULL
    return 0;
}