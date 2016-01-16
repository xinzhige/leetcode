class Solution {
public:
  int sumNumbers(TreeNode *root) {
    return sumNumbersHelper(root, 0);
  }
  
  int sumNumbersHelper(TreeNode *root, int num) {
    if (root == NULL) {
      return 0;
    }
    num = num * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
      return num;
    } else {
      return sumNumbersHelper(root->left, num)
	+ sumNumbersHelper(root->right, num);
    }
  }
};
