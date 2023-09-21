#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};
void addToHead(Node *&head, Node *&tail, int val)
{

    if (head == nullptr)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void printList(Node *&head)
{

    if (head == nullptr)
    {
        cout << "No list";
        return;
    }

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *middle(Node *&head, Node *&tail)
{

    if (head == nullptr)
        return nullptr;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;

    addToHead(head, tail, 50);
    addToHead(head, tail, 40);
    addToHead(head, tail, 30);
    addToHead(head, tail, 20);
    addToHead(head, tail, 10);

    printList(head);

    cout << endl
         << "Middle element is ";
    cout << middle(head, tail)->data;
}