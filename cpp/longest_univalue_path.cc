class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    univaluePath(root, ans);
    return ans;
  }
  int univaluePath(TreeNode* root, int &ans) {
    if (root == nullptr) {
      return 0;
    }
    int leftPath = univaluePath(root->left, ans);
    int rightPath = univaluePath(root->right, ans);
    int leftTemp = 0;
    int rightTemp = 0;
    if (root->left != nullptr && root->val == root->left->val) {
      leftTemp = leftPath + 1;
    }
    if (root->right != nullptr && root->val == root->right->val) {
      rightTemp = rightPath + 1;
    }
    ans = max(ans, leftTemp + rightTemp);
    return max(leftTemp, rightTemp);
  }
};
