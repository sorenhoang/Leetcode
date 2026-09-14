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
    int rob(TreeNode* root) {
        auto robDfs = dfs(root);
        return max(robDfs[0], robDfs[1]);
    }

    vector<int> dfs(TreeNode* root) {
        vector<int> ans(2, 0);
        if (root == nullptr)
            return ans;

        auto robInLeft = dfs(root->left);
        auto robInRight = dfs(root->right);
        ans[0] =
            max(robInLeft[0], robInLeft[1]) + max(robInRight[0], robInRight[1]);
        ans[1] = robInLeft[0] + robInRight[0] + (root->val);
        return ans;
    }
};