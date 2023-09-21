
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

void insertToHead(Node *&head, Node *&tail, int val)
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
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *middle(Node *&head)
{

    Node *fast = head->next;
    Node *slow = head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void removeDuplicates(Node *&head)
{

    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data != curr->data)
        {
            curr = curr->next;
        }
        else
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;

    insertToHead(head, tail, 50);
    insertToHead(head, tail, 40);
    insertToHead(head, tail, 40);
    insertToHead(head, tail, 20);
    insertToHead(head, tail, 10);
    insertToHead(head, tail, 0);

    printList(head);
    cout << endl
         << "middle term is " << middle(head)->data << endl;

    cout << "after removing duplicates" << endl;
    removeDuplicates(head);
    printList(head);
}