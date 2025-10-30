#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
using namespace std;

deque<int> dq;
int capacity = 4;

condition_variable not_full, not_empty;
mutex mtx;

void prodfunc(int thread_id)
{
    std::unique_lock<mutex> ul(mtx);
    not_full.wait(ul, [](){ return dq.size() < capacity? true : false;});
    cout<< "Inserted the count: "<< thread_id << "into queue" << endl;
    dq.push_back(thread_id);
    not_empty.notify_one();
}

void consfunc(int thread_id)
{
    std::unique_lock<mutex> ul(mtx);
    not_empty.wait(ul, [](){ return dq.size() > 0 ? true : false;});
    cout << "consumed : " << dq.front() << endl;
    dq.pop_front();
    not_full.notify_one();
}

int main()
{
    vector<thread> prodWorkers;
    vector<thread> consWorkers;

    for(int i = 0; i < 100; i++)
    {
        prodWorkers.emplace_back(prodfunc, i);
        consWorkers.emplace_back(consfunc, i);
    }

    for(auto& t : prodWorkers)
    {
        t.join();
    }

    for(auto& t : consWorkers)
    {
        t.join();
    }

    return 0;

}