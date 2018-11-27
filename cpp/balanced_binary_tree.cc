// Time: O(n), only traverse each node once.
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    return depth(root) != -1;
  }

private:
  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    if (left_depth == -1 || right_depth == -1 ||
        abs(left_depth - right_depth) > 1) {
      return -1;
    }
    return 1 + max(left_depth, right_depth);
  }
};
