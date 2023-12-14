#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int val)
    {

        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *buildTree()
{

    int data;
    cout << "enter data" << endl;
    cin >> data;
    if (data == -1)
        return nullptr;

    node *root = new node(data);

    cout << "enter data left of " << data << endl;
    root->left = buildTree();

    cout << "enter data right of " << data << endl;
    root->right = buildTree();

    return root;
}

void inorder(node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << endl;

    inorder(root->left);
    inorder(root->right);
}

int main()
{
    node *root = nullptr;

    root = buildTree();

    inorder(root);
    return 0;
}