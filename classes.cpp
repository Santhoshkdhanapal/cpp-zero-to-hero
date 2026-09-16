#include <iostream>

class Player {
    int score;

    // Constructor: runs automatically when Player is created
    Player() {
        score = 100;
        std::cout << "Player created with score: " << score;
    }
};

int main() {
    Player p; // Output: Player created with score: 100
    std::cin.get();
}