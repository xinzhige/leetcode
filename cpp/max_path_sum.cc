class Solution {
public:
  int maxPathSum(TreeNode *root) {
    max_sum = INT_MIN;
    maxPathSumHelper(root);
    return max_sum;
  }
private:
  int max_sum;
  int maxPathSumHelper(const TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_path_sum = maxPathSumHelper(root->left);
    int right_path_sum = maxPathSumHelper(root->right);
    int sum = root->val;
    if (left_path_sum > 0) {
      sum += left_path_sum;
    }
    if (right_path_sum > 0) {
      sum += right_path_sum;
    }
    max_sum = max(max_sum, sum);
    int maxSubTreeSum = max(left_path_sum, right_path_sum);
    return maxSubTreeSum > 0 ? maxSubTreeSum + root->val : root->val;
  }
};
