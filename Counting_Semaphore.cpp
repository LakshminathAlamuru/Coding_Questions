#include<iostream>
#include<semaphore>
#include<thread>
using namespace std;

std::counting_semaphore<5> cs(3);

void worker(int thread_number)
{
    std::cout << "Worker " << thread_number << " waiting...\n";
    cs.acquire();
    cout << "Worker thread: "<< thread_number << "acquired lock" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Worker thread: "<< thread_number << "released lock" << endl;
    cs.release();
}

int main()
{
    vector<thread> v;
    for(int i = 0; i < 5; i++)
    {
        v.emplace_back(worker, i);
    }
    for(auto &t : v)
    {
        t.join();
    }
    return 0;
}