/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int sumNumbersHelper(TreeNode* root, int num) {
    if (root == nullptr) {
      return 0;
    }
    int tmp = 10 * num + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return tmp;
    }
    return sumNumbersHelper(root->left, tmp) +
      sumNumbersHelper(root->right, tmp);
  }

  int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
  }
};
