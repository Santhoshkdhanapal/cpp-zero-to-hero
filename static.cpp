#include <iostream>
using namespace std;

class Student{
public:
    static void showMessage() {
        cout << "Welcome to C++ Programming";
    }
};

int main() {

    Student::showMessage();

    return 0;
}