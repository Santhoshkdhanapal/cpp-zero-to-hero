#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}

    int area() {
        return length * breadth;
    }
};

int main() {
    unique_ptr<Rectangle> ptr1 = make_unique<Rectangle>(10, 5);

    cout << ptr1->area() << endl;

    unique_ptr<Rectangle> ptr2 = move(ptr1);

    cout << ptr2->area();
    

    return 0;
}