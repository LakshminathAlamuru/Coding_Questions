#include<iostream>
#include<list>
using namespace std;

class ISubscriber{
    public:
        virtual ~ISubscriber() = default;
        virtual void notify(string msg) = 0;
};

class user: public ISubscriber{
    private:
        int userid;
    public:
        user(int id)
        {
            userid = id;
        }
        void notify(string msg) override
        {
            cout << " Message notified for " << userid << endl;
        }
};

class group{
    private:
    // this list can hold pointers to any object that implements the ISubscriber interface
            list<ISubscriber*> users;
    public:
        void subsrcibe(ISubscriber *usr)
        {
            users.push_back(usr);
        }

        void unsubscribe(ISubscriber *usr)
        {
            users.remove(usr);
        }

        void notifyAll(string msg)
        {
            for(auto usr: users)
            {
                usr->notify(msg);
            }
        }
};


int main()
{
    group *grp = new group();

    user *usr1 = new user(1);
    user *usr2 = new user(2);
    user *usr3 = new user(3);

    grp->subsrcibe(usr1);
    grp->subsrcibe(usr2);
    grp->subsrcibe(usr3);

    grp->notifyAll("Notify to 3 users");

    grp->unsubscribe(usr3);

    grp->notifyAll("Notify to just 2 Users");


    return 0;
}