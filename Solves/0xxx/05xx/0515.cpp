#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> max_arr;

        traversal(root, 0, max_arr);

        return max_arr;
    }

    void traversal(TreeNode *cur, int depth, vector<int> &max_arr)
    {
        if (cur == nullptr)
        {
            return;
        }
        if (depth >= max_arr.size())
        {
            max_arr.push_back(INT32_MIN);
        }
        int max_val = max_arr[depth];

        max_val = max(max_val, cur->val);
        max_arr[depth] = max_val;
        if (cur->left != nullptr)
        {
            traversal(cur->left, depth + 1, max_arr);
        }
        if (cur->right != nullptr)
        {
            traversal(cur->right, depth + 1, max_arr);
        }
    }
};

int main()
{
    // Input: root = [1,3,2,5,3,null,9]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    Solution sol;
    vector<int> res = sol.largestValues(root);
    for (int val : res)
        cout << val << " ";
    return 0;
}