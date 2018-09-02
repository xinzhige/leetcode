class Solution {
public:
  int largestBSTSubtree(TreeNode* root) {
    int result = 0;
    int mn = INT_MIN;
    int mx = INT_MAX;
    isValidBST(root, mn, mx, result);
    return result;
  }
  void isValidBST(TreeNode *root, int &mn, int &mx, int &result) {
    if (root != nullptr) {
      int left_n = 0;
      int right_n = 0;
      int left_mn = INT_MIN;
      int right_mn = INT_MIN;
      int left_mx = INT_MAX;
      int right_mx = INT_MAX;
      isValidBST(root->left, left_mn, left_mx, left_n);
      isValidBST(root->right, right_mn, right_mx, right_n);
      if ((root->left == nullptr || root->val > left_mx) &&
          (root->right == nullptr || root->val < right_mn)) {
        result = left_n + right_n + 1;
        mn = root->left == nullptr ? root->val : left_mn;
        mx = root->right == nullptr ? root->val : right_mx;
      } else {
        result = max(left_n, right_n);
      }
    }
  }
};
