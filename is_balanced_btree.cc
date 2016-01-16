// method 1: check if the current substree is balanced by computing height
class Solution {
public:
  int treeHeight(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
  }
  bool isBalanced(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    int left_height = treeHeight(root->left);
    int right_height = treeHeight(root->right);
    if (abs(left_height-right_height) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }
};
