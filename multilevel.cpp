#include <iostream>
using namespace std;

class Vehicle
{
  public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// Derived class from Vehicle
class FourWheeler : public Vehicle
{
  public:
    FourWheeler()
    {
        cout << "4 Wheeler Vehicles" << endl;
    }
};

// Derived class from FourWheeler
class Car : public FourWheeler
{
  public:
    Car()
    {
        cout << "This 4 Wheeler Vehicle is a Car" << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}