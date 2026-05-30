/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderBST(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL) return;
        inorderBST(root->left, ans);
        ans.push_back(root->val);
        inorderBST(root->right,ans);
    }

        int helper(TreeNode * root, int k){
        vector<int> ans;

        inorderBST(root, ans);

        return ans[k - 1];
    }

    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};