// if one node has not left child, then its minDepth must be the minDepth of its right child and so does its right child.
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_height = minDepth(root->left);
    int right_height = minDepth(root->right);
    if (root->left == nullptr) {
      return 1 + right_height;
    }
    if (root->right == nullptr) {
      return 1 + left_height;
    }
    return left_height < right_height ? 1 + left_height : 1 + right_height;
  }
};
