class Solution {
public:
  int rob(TreeNode* root) {
    int l = 0;
    int r = 0;
    return helper(root, l, r);
  }
  int helper(TreeNode* node, int& l, int& r) {
    if (node == nullptr) {
      return 0;
    }
    int ll = 0;
    int lr = 0;
    int rl = 0;
    int rr = 0;
    l = helper(node->left, ll, lr);
    r = helper(node->right, rl, rr);
    return max(node->val + ll + lr + rl + rr, l + r);
  }
};
