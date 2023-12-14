#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool solve(TreeNode *root, long long int lb, long long int ub)
{

    if (root->val >= lb && root->val <= ub)
    {
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);

        return leftAns && rightAns;
    }
    else
    {
        return false;
    }
}

bool validateBST(TreeNode *root)
{

    if (root == nullptr)
        return false;

    long long int lb = LLONG_MIN;
    long long int ub = LLONG_MAX;

    return solve(root, lb, ub);
}

int main()
{
}