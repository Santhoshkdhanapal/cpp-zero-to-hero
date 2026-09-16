#include <iostream>

class Player {
public:
     int score;
     Player(){
        score = 50;
        std::cout << "Constructor Triggerred automatically\n";
             }

};

int main(){
    Player p;
    std::cout << "Score: " << p.score << "\n";
}