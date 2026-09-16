#include <iostream>
class Safe{
    private:
      int pin =0404;
    public:
      bool verify(int p){
        return p == pin;
      }
};

int main(){
    Safe s;
    std::cout << "Try 0101:" << (s.verify(0101) ? "Access granted" : "Access Denied") << "\n";
    std::cout << "Try 0404:" << (s.verify(0404) ? "Access granted" : "Access Denied") << "\n";
}