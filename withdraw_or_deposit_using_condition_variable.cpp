#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex m;
std::condition_variable cv;
long balance = 0;

void WithdrawMoney(int money)
{
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [] { return (balance != 0)? true: false ; });
    if(balance >= money)
    {
        cout << "Amount Deducted: " << money << endl;
    }
    else
    {
        cout << "Amount can't be deducted, Current Balance is just " << balance << endl;
    }
    cout << "Current balance is: " << balance << endl;
}

void AddMoney(int money)
{
    std::unique_lock<mutex> lg(m);
    balance = balance+money;
    cout << "Amount Added, Current Balance: " << balance << endl;
    cv.notify_one();
}

int main()
{
    thread t1(WithdrawMoney, 500);
    thread t2(AddMoney, 500);
    t1.join();
    t2.join();
    return 0;
}