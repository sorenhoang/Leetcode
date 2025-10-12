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
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        // Queue stores pairs of {node, index}
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0}); // Root starts at index 0

        while (!q.empty())
        {
            int size = q.size();
            // Step 1: Get minimum index of current level to normalize
            long long minn = q.front().second;
            long long first, last;

            // Step 2: Process all nodes at current level
            for (int i = 0; i < size; i++)
            {
                // Step 3: Normalize index to prevent overflow
                long long cur_ind = q.front().second - minn;
                TreeNode *node = q.front().first;
                q.pop();

                // Track first and last indices at this level
                if (i == 0)
                    first = cur_ind;
                if (i == size - 1)
                    last = cur_ind;

                // Step 4: Add children with their indices
                if (node->left)
                    q.push({node->left, cur_ind * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_ind * 2 + 2});
            }

            // Step 5: Calculate width for this level
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};