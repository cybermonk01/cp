#include <iostream>
#include <vector>
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

vector<int> diagonal(node *root)
{

    vector<int> ans;

    if (root == nullptr)
        return ans;

    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        while (temp)
        {
            ans.push_back(temp->data);

            if (temp->left)
            {
                q.push(temp->left);
            }
            temp->right->right;
        }
    }
    return ans;
}

int main()
{

    node *root = nullptr;
    root = buildTree();

    diagonal(root);

    // inorder(root);

    return 0;
}
