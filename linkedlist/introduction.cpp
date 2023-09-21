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

void printList(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertToHead(Node *&head, Node *&tail, int val)
{

    if (head == NULL)
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

void insertToTail(Node *&head, Node *&tail, int val)
{

    if (head == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(val);
    tail->next = newNode;
    newNode = tail;
}

void insertAtPosition(int val, Node *&head, Node *&tail, int pos)
{
    if (pos == 1 || head == nullptr)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        return;
    }

    int i = 1;
    Node *prev = head;
    while (i < pos - 1 && prev != nullptr)
    {
        prev = prev->next;
        i++;
    }

    Node *curr = prev->next;
    Node *newNode = new Node(val);
    newNode->next = curr;
    prev->next = newNode;

    // Check if inserting at the last position
    if (curr == nullptr)
    {
        tail = newNode;
    }
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;
    insertToHead(head, tail, 20);
    insertToHead(head, tail, 30);

    insertToTail(head, tail, 10);
    insertToTail(head, tail, 0);

    insertAtPosition(5, head, tail, 2);

    // deleteStart(head, tail, )
    printList(head);
}