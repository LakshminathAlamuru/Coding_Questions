#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class CircularBuffer
{
    public:
        vector<int> buffer;
        mutex m;
        condition_variable not_empty;
        condition_variable not_full;
        int capacity;
        int count = 0;
        int head = 0;
        int tail = 0;

        explicit CircularBuffer(int c)
        {
            buffer.resize(c);
            capacity = c;
        }

    void addItem(int item)
    {
        unique_lock<mutex> ul(m);
        not_full.wait(ul,[this](){return count < capacity;});
        buffer[tail] = item;
        tail = ++tail%capacity;
        count++;
        not_empty.notify_one();
    }

    int getItem()
    {
        unique_lock<mutex> ul(m);
        not_empty.wait(ul, [this](){ return count > 0;});
        int item = buffer[head];
        head = ++head%capacity;
        count--;
        not_full.notify_one();
        return item;
    }           
};

CircularBuffer cb(5);
void ProdWorker(int thread_number)
{
    for(int i = 0; i < 10; i++)
    {
        int item = thread_number*i;
        cout << "Add Item: " << item <<" by thread: " << thread_number << endl;
        cb.addItem(item);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void ConsWorker(int thread_number)
{
    for(int i = 0; i < 10; i++)
    {
        int item = cb.getItem();
        cout << "Consumed Item: " << item <<" by thread: " << thread_number << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    vector<thread> producers;
    vector<thread> consumers;

    for(int i = 0; i < 5; i++)
    {
        producers.emplace_back(ProdWorker, i);
        consumers.emplace_back(ConsWorker, i);
    }

    for(auto &t: producers)
    {
        t.join();
    }

    for(auto &t: consumers)
    {
        t.join();
    }
    return 0;
}