class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    if (root->left == NULL && root->right == NULL) {
      return 1;
    }
    int left_height = minDepth(root->left);
    int right_height = minDepth(root->right);
    if (root->left == NULL) {
      return 1 + right_height;
    }
    if (root->right == NULL) {
      return 1 + left_height;
    }
    return left_height < right_height ? 1+left_height : 1+right_height;
  }
};
