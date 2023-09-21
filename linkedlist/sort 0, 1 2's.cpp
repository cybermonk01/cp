
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

void sorting(Node *&head)
{

    int zero = 0;
    int ones = 0;
    int twos = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            ones++;
        }
        else if (temp->data == 2)
        {
            twos++;
        }
        temp = temp->next;
    }

    temp = head;

    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (ones--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (twos--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;

    insertToHead(head, tail, 2);
    insertToHead(head, tail, 1);
    insertToHead(head, tail, 2);
    insertToHead(head, tail, 1);
    insertToHead(head, tail, 1);
    insertToHead(head, tail, 0);

    printList(head);
    //   cout<<endl<<"middle term is "<<middle(head)->data<<endl;

    // cout<<"after removing duplicates"<<endl;
    // removeDuplicates(head);

    sorting(head);
    printList(head);
}