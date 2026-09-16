#include <iostream>

struct S{
    int x=2;
};

class C{
    int x=12;
};

int main(){
    S s;
    std::cout << "Struct default Public x:" << s.x << "\n";
}