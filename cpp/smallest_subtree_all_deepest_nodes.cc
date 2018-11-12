class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).first;
  }
  // The first element of pair is the deepest node or an ancestor of
  // all the deepest nodes of this subtree.
  // The second one is the number of nodes in the path from the root of
  // this subtree to the deepest node in this subtree.
  pair<TreeNode *, int> dfs(TreeNode* root) {
    if (root == nullptr) {
      pair<TreeNode *, int> tmp{nullptr, 0};
      return tmp;
    }
    auto L = dfs(root->left);
    auto R = dfs(root->right);
    if (L.second > R.second) {
      pair<TreeNode *, int> tmp{L.first, L.second + 1};
      return tmp;
    }
    if (L.second < R.second) {
      pair<TreeNode *, int> tmp{R.first, R.second + 1};
      return tmp;
    }
    pair<TreeNode *, int> tmp{root, L.second + 1};
    return tmp;
  }
};
