#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
}

void
buildTree(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        buildTree(root->left, data);
    }
    else
    {
        buildTree(root->right, data);
    }
}

void insert(Node *root)
{

    int data;
    cout << "enter data" << endl;
    cin >> data;

    while (data != -1)
    {
        buildTree(root, data);
        cin >> data;
    }
}

void inOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inOrder(root->left);
    inOrder(root->right);
}

int main()
{

    Node *root = NULL;

    insert(root);
}