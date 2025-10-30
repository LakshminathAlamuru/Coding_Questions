#include<iostream>
#include<memory>

using namespace std;
class MyInt{
    public:
        int *data;
        explicit MyInt(int *p = nullptr)
        {
            data = p;
        }
        int& operator * () {
            return *data;
        }
        ~MyInt()
        {
            delete data;
        }
};

int main()
{
    int *p = new int(10);
    // smart pointers allocates in heap, since in destructors , it can delete the object
    MyInt sp = MyInt(p);
    cout << *sp << endl;
    return 0;
}