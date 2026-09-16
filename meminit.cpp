#include <iostream>

class Point{
    public:
     int x,y;
     Point(int a, int b) : x(a), y(b){}
};

int main(){
    Point p(7, 9);
    std::cout << "Point Coordinates: (" << p.x << "." <<p.y<<")"
}