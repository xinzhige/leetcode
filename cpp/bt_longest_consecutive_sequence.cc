class Solution {
public:
  int longestConsecutive(TreeNode* root) {
    return dfs(root, nullptr, 0);
  }
private:
  int dfs(TreeNode* node, TreeNode* parent, int len) {
    if (node == nullptr) {
      return len;
    }
    if (parent != nullptr && node->val == parent->val + 1) {
      len += 1;
    } else {
      len = 1;
    }
    return max(len, max(dfs(node->left, node, len),
                        dfs(node->right, node, len)));
  }
};
