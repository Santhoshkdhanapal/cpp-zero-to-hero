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

class Fare
{
  public:
    Fare()
    {
        cout << "Fare of Vehicle" << endl;
    }
};

class Car : public Vehicle
{
  public:
    Car()
    {
        cout << "This Vehicle is a Car" << endl;
    }
};

class Bus : public Vehicle, public Fare
{
  public:
    Bus()
    {
        cout << "This Vehicle is a Bus with Fare";
    }
};

int main()
{
    Bus obj2;
    return 0;
}