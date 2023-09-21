#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

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
    cout << "Enter the data" << endl;
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

void levelOrder(node *root)
{

    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *current = q.front();
        cout << current->data << endl;
        q.pop();

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

void inorder(node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int Diameter(node *root, int &res)
{

    if (root == nullptr)
        return 0;

    int leftDia = Diameter(root->left, res);
    int rightDia = Diameter(root->right, res);

    int tempDia = max(leftDia, rightDia) + 1;
    int ans = max(tempDia, 1 + leftDia + rightDia);
    res = max(res, ans);

    return tempDia;
}

//  1 3 5 -1 -1 7 -1 -1 9 11 -1 -1 13 15 -1 -1 -1
int main()
{

    node *root = nullptr;

    root = buildTree();

    int res = INT_MIN;
    inorder(root);

    cout << "level order" << levelOrder(root);

    int dia = Diameter(root, res);

    cout << "maximum diameter is " << dia << endl;
}