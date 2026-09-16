#include <iostream>

class Player{
    public:
    int health = 100;
};

int main(){
    Player p;
    std::cout << "Player Health:" << p.health << "/n";
}