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

    cout << "enter value left of " << data << endl;
    root->left = buildTree();

    cout << "enter value right of " << data << endl;
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

int maxSumPathLeaf(node *root, int &res)
{

    if (root == nullptr)
        return 0;

    int l = maxSumPathLeaf(root->left, res);
    int r = maxSumPathLeaf(root->right, res);

    // induction

    int temp = max(l, r) + root->data;
    int ans = max(temp, root->data + l + r);
    res = max(res, ans);

    return temp;
}

int sumTree(node *root, int &res)
{

    if (root == nullptr)
        return 0;

    int leftAns = sumTree(root->left, res);
    int rightAns = sumTree(root->right, res);
    root->data = leftAns + root->data + rightAns;

    return root->data;
}
int main()
{

    node *root = nullptr;

    root = buildTree();
    int res = INT_MIN;
    cout << sumTree(root, res);
    inorder(root);
}