#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

class CountingSemaphore{
    public:
        int count;
        std::mutex m;
        std::condition_variable cv;
        //explicit constructor for CountingSemaphore
        explicit CountingSemaphore(int initialCount)
        {
            count = initialCount;
        }

        void acquire()
        {
            std::unique_lock<mutex> ul(m);
            cout << "Wait until count is greater than 0, count: " << count << endl;
            cv.wait(ul, [this](){return count > 0;});
            count--;
        }

        void release()
        {
            std::lock_guard<mutex> lg(m);
            count++;
            cv.notify_all();
        }
};

CountingSemaphore cs(2);

void worker(int thread_number)
{
    std::cout << "Worker " << thread_number << " waiting...\n";
    cs.acquire();
    cout << "Worker thread: "<< thread_number << " acquired lock" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Worker thread: "<< thread_number << " released lock" << endl;
    cs.release();
}

int main()
{
    vector<thread> v;
    for(int i = 0; i < 5; i++)
    {
        v.emplace_back(worker, i);
    }

    for(auto &t: v)
    {
        t.join();
    }
    return 0;
}