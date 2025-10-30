#include<iostream>

using namespace std;

class Singleton{
    private:
        //constructor has to be private
        Singleton() {};
        static Singleton* instancePtr;
        static mutex mtx;
    public:
        //Copy constructor should be deleted;
        Singleton(const Singleton& obj) = delete;
        static Singleton *getInstance()
        {
            if(instancePtr == nullptr)
            {
                lock_guard<mutex> lock(mtx);
                if(instancePtr == nullptr)
                {
                    instancePtr = new Singleton();
                    cout << "Instance created for the first time" << endl;
                }
            }
            return instancePtr;
        }
        void show()
        {
            cout << "Show function from the singleton" << endl;
        }
};

//Initialize Singleton Ptr;
Singleton *Singleton::instancePtr = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *s = Singleton::getInstance();
    Singleton *s2(s);
    //s->show();
    s2->show();
    return 0;
}