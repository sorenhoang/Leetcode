class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();

    // left call stack, behavior depends on inorder next element
    // whether to explore right subtree or go up
    vector<TreeNode *> path;

    TreeNode *root = new TreeNode(preorder[0]);
    path.push_back(root);
    int pi = 1;
    int ii = 0;

    while (!path.empty() && pi < n) {
      if (path.back()->val != inorder[ii]) {
        TreeNode *curr = new TreeNode(preorder[pi++]);
        path.back()->left = curr;
        path.push_back(curr);
        continue;
      }

      // here we know that no further left children left for .back() node

      TreeNode *curr = path.back();
      path.pop_back();
      ++ii;

      // check whether parent node is next (no right subtree for inorder)
      if (!path.empty() && ii < n && path.back()->val == inorder[ii]) {
        continue;
      }

      TreeNode *next = new TreeNode(preorder[pi++]);
      curr->right = next;
      // inserted element can also have left children
      path.push_back(next);
    }
    return root;
  }
};