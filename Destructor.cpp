#include <iostream>

class file{
    public:
    file(){ std::cout << "file opened\n";}
    ~file() {std::cout  << " file closed automatically\n";}
};

int main(){
    {
        file f;
    }
    std::cout << "Scope ended\n";
}
