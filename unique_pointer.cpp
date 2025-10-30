//unique pointer
//Ownership : unique_ptr owns the object it points to. Only unique_ptr can own an object at a time
//Move Semantics: It cannot be copied, it can be just moved
//Memory management: It automatically deletes the object it points to when it goes out of scope, so there is no need to manually call delete.

#include<iostream>
#include<memory>

struct A{
    void printA(){
        std::cout << "A struct ...." << std::endl;
    }
};

int main()
{
    std::unique_ptr<A> p1(new A);
    p1->printA();

    //will give compile error, copy constructor doesn't support here
    //std::unique_ptr<A> p2(p1);

    std::unique_ptr<A> p2;
    p2 = move(p1);
    p2->printA();

    return 0;
}