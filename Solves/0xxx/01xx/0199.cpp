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
private:
    vector<int> ans;

public:
    vector<int> rightSideView(TreeNode* root) {
        DFS(root, 1);
        return ans;
    }

    void DFS(TreeNode* root, int height) {
        if (root == nullptr)
            return;
        if (height > ans.size())
            ans.push_back(0);

        ans[height - 1] = root->val;
        DFS(root->left, height + 1);
        DFS(root->right, height + 1);
    }
};
