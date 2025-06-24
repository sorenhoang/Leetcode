// LeetCode 951. Flip Equivalent Binary Trees
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true; // Both nodes are null
        if (root1 == nullptr || root2 == nullptr)
            return false; // One of the nodes is null
        if (root1->val != root2->val)
            return false; // Values do not match

        if (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
        {
            return true; // No flip needed
        }

        if (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
        {
            return true; // Flip needed
        }

        return false;
    }
};

int main()
{
    Solution sol;
    // Example usage:
    TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *root2 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    cout << (sol.flipEquiv(root1, root2) ? "true" : "false") << endl; // Should output true
    return 0;
}