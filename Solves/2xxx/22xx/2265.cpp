/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) { return *dfs(root).begin(); }

    vector<int> dfs(TreeNode* root) {
        vector<int> curNode(3, 0);

        if (root == nullptr)
            return curNode;

        auto leftNode = dfs(root->left);
        auto rightNode = dfs(root->right);

        curNode[1] = leftNode[1] + rightNode[1] + 1;
        curNode[2] = leftNode[2] + rightNode[2] + root->val;
        curNode[0] = leftNode[0] + rightNode[0] +
                     (root->val == curNode[2] / curNode[1]);
        return curNode;
    }
};