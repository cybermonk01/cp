#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }

~Node(){
  cout<<"node with value"<<this->data<<" deleted";
}
};
void insertToHead(Node *&head, Node *&tail, int val)
{

    if (head == nullptr)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    // createa a new node
    Node *newNode = new Node(val);

    // attach to head;
    newNode->next = head;

    // update head prev from null to newNode
    head->prev = newNode;

    // update head to get the new Node;
    head = newNode;
}

void insertToTail(Node*&head, Node*&tail, int val)
{

    if (head == nullptr)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(val);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int getLength(Node *&head)
{
    int len = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPos(Node *&head, Node *&tail, int val, int pos)
{
    int len = getLength(head);
    if (pos == 1)
    {
        insertToHead(head, tail, val);
        return;
    }
    else if (pos > len)
    {

insertToTail(head, tail, val);
return;
    }

    int i = 1;
    Node *prevNode = head;

    while (i < pos - 1)
    {
        prevNode = prevNode->next;
        i++;
    }
    Node *curr = prevNode->next;

    Node *newNode = new Node(val);

    newNode->prev = prevNode;
    prevNode->next = newNode;
    curr->prev = newNode;
    newNode->next = curr;
}

void deleteFromPos(Node *&head, Node *&tail, int pos)
{
    int len = getLength(head);

    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    if (head->next == nullptr)
    {
        Node *temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }

    if (pos == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }

    int i = 1;
    Node *left = head;
    while (i < pos)
    {
        left = left->next;
        i++;
    }

    Node *curr = left->next;
    Node *right = curr->next;

    left->next = right;
    right->prev = left;

    curr->prev = nullptr;
    curr->next = nullptr;
    delete curr;
}


void printList(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;
    // insertToHead(head, 40);

    insertToHead(head, tail, 40);
    insertToTail(head, tail, 60);
    insertToTail(head, tail, 80);
    insertAtPos(head, tail, 70, 3);
  deleteFromPos(head,tail, 1);
    printList(head);
}