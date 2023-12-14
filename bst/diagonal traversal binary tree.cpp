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
};
vector<int> diagonal(Node *root, vector<int> &ans)
{

    if (root == nullptr)
        return ans;

    queue<Node *> q;
    q.push_back(root);
    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        while (temp)
        {
            ans.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(15);
    Node *second = new Node(4);
    Node *third = new Node(6);
    Node *fourth = new Node(2);
    Node *fifth = new Node(25);
    Node *sixth = new Node(27);
    Node *seventh = new Node(35);

    root->left = second;
    second->left = fourth;
    second->right = third;
    root->right = fifth;
    fifth->left = sixth;
    fifth->right = seventh;

    vector<int> ans;
    diagonal(root, ans);

    for (auto val : ans)
    {
        cout << val << " ";
    }
}