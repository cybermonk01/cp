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

bool kthAncestor(node *root, int &k, int p)
{
    if (root == nullptr)
        return false;

    // here it is checking whether the root is equal to the p and if then return true
    if (root->data == p)
        return true;
    // if not get p then check both the left and right ans
    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);
    // if either of left or right gives p then k should be minus and  should be minus unitl value becomes 0 then when k = 0 print the data and then make k = -1 so that no other value gets print so we get only one answer;
    if (leftAns || rightAns)
    {
        k--;

        if (k == 0)
        {
            cout << "Answer is " << root->data << " ";
            k = -1;
        }
    }
}

int main()
{

    node *root = nullptr;
    root = buildTree();

    int k = 1;
    int p = 5;

    // we have to send the p node whose ancestor has to be checked and k means how many levels up ancestor has to be searched
    kthAncestor(root, k, p);

    inorder(root);

    return 0;
}
