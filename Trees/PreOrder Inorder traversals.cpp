
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
#include <iostream>
using namespace std;

class Solution
{
public:
    int findPos(vector<int> &inorder, int element, int size)
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

    int createNodeToIndex(vector<int> &inorder, int preIndex, int size)
    {

        for (int i = 0; i < size; i++)
        {
            map[inorder[preIndex]] = i;
        }
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStart, int inorderEnd, int size)
    {

        if (preIndex >= size || inorderStart > inorderEnd)
        {
            return nullptr;
        }

        int element = preorder[preIndex++];
        TreeNode *root = new TreeNode(element);
        int position = findPos(inorder, element, size);

        root->left = solve(preorder, inorder, preIndex, inorderStart, position - 1, size);
        root->right = solve(preorder, inorder, preIndex, position + 1, inorderEnd, size);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = inorder.size();
        createNodeToIndex(inorder, preIndex, size);

        TreeNode *ans = solve(preorder, inorder, preIndex, inorderStart, inorderEnd, size);
        return ans;
    }
};