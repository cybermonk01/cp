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
    cout << "enter data";
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

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *lca(node *root, node *p, node *q)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == p->data)
    {
        return p;
    }

    if (root->data == q->data)
    {
        return q;
    }

    node *leftAns = lca(root->left, p, q);
    node *rightAns = lca(root->right, p, q);

    if (leftAns != nullptr && rightAns == nullptr)
        return leftAns;

    else if (leftAns == nullptr && rightAns != nullptr)
        return rightAns;
    else if (leftAns == nullptr && rightAns == nullptr)
        return nullptr;
    else
        return root;
}

int main()
{

    node *root = nullptr;
    root = buildTree();

    node *p = new node(1);
    node *q = new node(5);

    // we have to send the p node whose ancestor has to be checked and k means how many levels up ancestor has to be searched
    node *lowestCommonAncestor = lca(root, p, q);
    if (lowestCommonAncestor != nullptr)
    {
        cout << "Lowest Common Ancestor: " << lowestCommonAncestor->data << endl;
    }
    else
    {
        cout << "No common ancestor found." << endl;
    }

    inorder(root);

    return 0;
}
