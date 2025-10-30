#include <iostream>
#include <list>
using namespace std;

class ISubscribe
{
    public:
        virtual void notify(string str) = 0;
        virtual ~ISubscribe() {};
};

class User : public ISubscribe
{
    public:
        int userid;
        User(int userid)
        {
            this->userid = userid;
        }
        void notify(string str)
        {
            cout << "User: " << userid << "got: " << str << endl;
        }
};

class Group {
    public:
        list<ISubscribe*> users;
        void subscribe(ISubscribe* usr)
        {
            users.push_back(usr);
        }
        void unsubscribe(ISubscribe* usr)
        {
            users.remove(usr);
        }
        void notify(string str)
        {
            cout << "Notified all users that they got msg" << endl;
            for(auto u: users)
            {
                u->notify(str);
            }
        }
};

int main()
{
    Group *group = new Group();

    User *usr1 = new User(1);
    User *usr2 = new User(2);
    User *usr3 = new User(3);

    group->subscribe(usr1);
    group->subscribe(usr2);
    group->subscribe(usr3);

    group->notify("You have a msg");

    return 0;
}