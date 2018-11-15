class Solution {
public:
  int longestConsecutive(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int result = dfs(root, 1) + dfs(root, -1) + 1;
    int curr_max = max(longestConsecutive(root->left),
                       longestConsecutive(root->right));
    return max(result, curr_max);
  }
  int dfs(TreeNode* root, int diff) {
    if (root == nullptr) {
      return 0;
    }
    int l = 0;
    int r = 0;
    if (root->left != nullptr && root->val == root->left->val + diff) {
      l = 1 + dfs(root->left, diff);
    }
    if (root->right != nullptr && root->val == root->right->val + diff) {
      r = 1 + dfs(root->right, diff);
    }
    return max(l, r);
  }
};
