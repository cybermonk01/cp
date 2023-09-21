#include <iostream>
#include <climits>
#include <algorithm>

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

    cout << "enter data left of " << data
         << endl;
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

int maxPathSum(node *root, int &res)
{

    if (root == nullptr)
        return 0;

    // hypothesis

    int l = maxPathSum(root->left, res);
    int r = maxPathSum(root->right, res);

    // induction

    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, root->data + l + r);
    res = max(res, ans);

    return temp;
}

int main()
{

    node *root = nullptr;

    root = buildTree();
    cout << endl;
    int res = INT_MIN;
    maxPathSum(root, res);

    inorder(root);
}
