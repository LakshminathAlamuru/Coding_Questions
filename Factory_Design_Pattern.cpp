#include<iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle()
        {
            cout << "Vehicle is ready" << endl;
        }

};

class car: public Vehicle
{

};

class bike: public Vehicle
{
    public:
        bike()
        {
            cout << "Bike is getting ready" << endl;
        }

};

class Toyota : public car{

};

class Yamaha : public bike{
    public:
        Yamaha()
        {
            cout << "Yamaha bike is ready" << endl;
        }

};

int main()
{
    Yamaha *y = new Yamaha();
    return 0;
}