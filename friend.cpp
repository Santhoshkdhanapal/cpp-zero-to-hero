#include <iostream>
using namespace std;

class GFG {
private:
    int value = 100;

    friend void display(GFG obj);
    friend class FriendClass;
};

void display(GFG obj) {
    cout << "Friend Function: " << obj.value << endl;
}

class FriendClass {
public:
    void show(GFG obj) {
        cout << "Friend Class: " << obj.value << endl;
    }
};

int main() {
    GFG obj;
    FriendClass f;

    display(obj);
    f.show(obj);

    return 0;
}