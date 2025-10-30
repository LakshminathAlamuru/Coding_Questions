#include<iostream>
using namespace std;

struct ListNode{
    int key, val;
    ListNode *prev, *next;
    ListNode(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache{
    public;
        int cap;
        unordered_map<int, ListNode*> mp;
        ListNode* head;
        ListNode* tail;

        LRUCache(int capacity)
        {
            cap = capacity;
            head = nullptr;
            tail = nullptr;
        }

        int get(int key) //if key is not found, return -1 , else value
        {
            if(mp.find(key) != mp.end())
            {
                moveToFront(mp[key]);
                return mp[key];
            }
            return -1;
        }

        void put(int key, int value)
        {
            //if key is not found, insert at beginning



            //if key is found, insert at beginning and delete from that point

        }


};

int main()
{
    LRUCache *obj = new LRUCache(4);
    return 0;
}