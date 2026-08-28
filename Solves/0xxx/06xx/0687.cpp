class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = 0, rightPath = 0;

        if (node->left && node->left->val == node->val) {
            leftPath = left + 1;
        }

        if (node->right && node->right->val == node->val) {
            rightPath = right + 1;
        }

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};