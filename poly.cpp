#include <iostream>
using namespace std;

class Animal {
public:
    // Function to display animal sound
    void sound() {
        cout << "Animal makes a sound";
    }
};

class Dog : public Animal {
public:
    // Overriding the sound function
    void sound() {
        cout << "Dog barks";
    }
};

int main() {
    Animal a;

    // Calling the Dog class function
    a.sound();

    return 0;
}