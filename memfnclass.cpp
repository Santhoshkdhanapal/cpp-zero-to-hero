#include <iostream>

class Player{
    public:
    int health = 100;
    void takeDamage(int dmg){
        health-=dmg;
    }
};

int main(){
    Player p;
    p.takeDamage(25);
    std::cout << "Health after Damage:" << p.health << "\n";
}