#include <iostream>
using namespace std;

class Animal{
    
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal{
    
public:

    // Override the virtual function
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main(){
    
    // Base class pointer pointing to derived class object
    Animal* a = new Dog();

    // Calls Dog's sound() due to virtual function
    a->sound();

    delete a; // Free allocated memory
    return 0;
}