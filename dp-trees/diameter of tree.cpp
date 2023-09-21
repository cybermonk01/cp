#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    {
        int data;
        node *left;
        node *right;

        node(int val)
        {
            this->data = val;
            this->left = nullptr;
            this->right = nullptr;
        }
    }
};

void buildTree()
{
    int data;
    cout << "enter data";
    cin >> data;

    if (data == -1)
        return nullptr;
    cout << "enter data left of " << data << endl;
    root->left = buildTree();
    cout << "enter data right of " << data << endl;
    root->right = buildTree();

    return root;
}

int main()
{

    node *root = nullptr;

    root = buildTree();
}
