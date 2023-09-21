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

bool checkPalindromes(Node *&head)
{
    if (head == NULL)
    {

        return true;
    }

    if (head->next == NULL)
    {
        return true;
    }

    Node *reverseLLHead = reverse(middle(head)->next);

    Node *temp1 = head;
    Node *temp2 = reverseLLHead;

    while (temp2 != NULL)
    {

        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;

    insertToHead(head, tail, 0);
    insertToHead(head, tail, 10);
    insertToHead(head, tail, 20);
    insertToHead(head, tail, 20);
    insertToHead(head, tail, 10);
    insertToHead(head, tail, 0);

    printList(head);
    cout << endl
         << "middle term is " << middle(head)->data;

    bool checkPalindrome = checkPalindromes(head);

    if (checkPalindrome == true)
    {
        cout << endl
             << "palindrome hai"
             << " ";
    }
    else
    {
        cout << endl
             << "nhi hai palindrome";
    }
}