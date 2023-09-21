// using fast and slow pointers

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
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *reverseK(Node *&head, int k)
{

    if (head == NULL)
    {
        cout << "No list" << endl;
    }

    int len = getLength(head);

    if (len < k)
    {
        cout << "k is larger than list size" << endl;
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }

    int count = 0;
    Node *left = NULL;
    Node *curr = head;
    Node *right = curr->next;

    while (count < k)
    {
        right = curr->next;
        curr->next = left;
        left = curr;
        curr = right;
        count++;
    }

    if (right != NULL)
    {
        head->next = reverseK(right, k);
    }

    return left;
}

int isLoop(Node *&head)
{

    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return 1;
        }
    }

    return 0;
}

Node *startingPoint(Node *&head)
{

    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
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
    // addToHead(head, tail, 5);

    Node *first = new Node(60);
    Node *sec = new Node(70);
    Node *third = new Node(80);
    tail->next = first;
    first->next = sec;
    sec->next = third;
    third->next = tail;

    // printList(head);
    cout << isLoop(head);

    // cout<<endl<<"Middle element is ";
    // cout<<middle(head, tail)->data<<endl;

    // head =reverseK(head, 3);
    //   printList(head);
}
