// C++ program to add one to a linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* reverse(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addOneUtil(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    int carry = 1;
    while(curr != nullptr && carry){
        carry = curr->data + carry;
        curr->data = carry%10;
        if(carry >= 10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        prev = curr;
        curr = curr->next;
    }
    if(carry > 1)
    {
        prev->next = new Node(1);
    }
    return head;
}

// Main function to add one to the linked list
Node *addOne(Node *head) {
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);
}

int addCarry(Node *head)
{
    if(head == nullptr)
    {
        return 1;
    }

}

Node *addOneRecur(Node *head)
{
    if(head == nullptr)
    {
        head = new Node(1);
        return head;
    }
    int res = head->data + addCarry(head->next);
    Node* temp;
    if ( res > 10)
    {
        temp = new Node(1);
        temp->next = head;
    }
    return temp;
\
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
  	// Create a hard-coded linked list:
    // 1 -> 9 -> 9 -> 9
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    //head = addOne(head);
    head = addOneRecur(head);
  
    printList(head);

    return 0;
}