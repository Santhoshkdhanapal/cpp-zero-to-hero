#include <iostream>
using namespace std;

int main() {
    int *ptr = new int[5];
    *(ptr + 2) = 10;   
    cout << *(ptr + 2);      
    delete[] ptr;            
    ptr = NULL;      
      // Access the third element in the array    
}