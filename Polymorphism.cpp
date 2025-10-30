#include <iostream>
using namespace std;

class Base {
public:
    virtual void speak() { cout << "Base speaking\n"; }
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived speaking\n"; }
};

int main() {
    Base* b = new Derived();
    b->speak();  // calls Derived::speak at runtime
}