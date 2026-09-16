#include <iostream>

class Counter{
    int val = 0;
public:
   Counter& add(int val){
     this->val += val;
     return *this;
   }
   void show(){ std::cout << "Final val:" << val << "\n";}
};

int main (){
    Counter c;
    c.add(5).add(10).add(20);
    c.show();
}