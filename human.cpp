#include <iostream>
#include <string>

class Good_Emotion{
    public:
    
    char m_happy{};
    char m_joy{};
    char m_laugh{};
 };

 class Bad_Emotion{
    public:
    char m_attitude{};
    char m_shout{};
    char m_rude{};
 };

 void printGood_Emotion(const Good_Emotion& good_Emotion)
{
    std::cout << good_Emotion.m_happy << " Beautiful Emotion";
}

int main() {
    // Instantiating the object
    Good_Emotion today{ 'V', 'L', 'c' };

    // Calling the function
    printGood_Emotion(today);

    return 0;
}