#include <iostream>
#include <queue>
#include <vector>

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

void inorderr(node *root)
{

    if (root == nullptr)
        return;

    inorderr(root->left);
    cout << root->data << " ";
    inorderr(root->right);
}

void levelOrder(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
                q.push(temp->right);
        }
    }
}
int findPos(vector<int> inorder, int element, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

node *solve(vector<int> inorder, vector<int> postorder, int &postIndex, int size, int inorderStart, int inorderEnd)
{

    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return nullptr;
    }

    int element = postorder[postIndex--];

    node *root = new node(element);
    int pos = findPos(inorder, element, size);

    root->left = solve(inorder, postorder, postIndex, size, inorderStart, pos - 1);
    root->right = solve(inorder, postorder, postIndex, size, pos + 1, inorderEnd);

    return root;
}
int main()
{

    vector<int> inorder = {
        40,
        20,
        10,
        50, 30, 60};
    vector<int> postorder = {40,
                             20,
                             50,
                             60,
                             30, 10};

    int size = inorder.size();
    int inorderStart = 0;
    int inorderEnd = size - 1;
    int postIndex = size - 1;

    node *root = solve(inorder, postorder, postIndex, size, inorderStart, inorderEnd);

    cout << endl
         << "level order" << endl;
    levelOrder(root);
    return 0;
}
