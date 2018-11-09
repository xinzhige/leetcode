class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
  }
  TreeNode* dfs(vector<int>& nums, int begin, int end) {
    if (begin <= end) {
      int idx = maxIdx(nums, begin, end);
      auto node = new TreeNode(nums[idx]);
      auto left = dfs(nums, begin, idx - 1);
      auto right = dfs(nums, idx + 1, end);
      node->left = left;
      node->right = right;
      return node;
    }
    return nullptr;
  }
  int maxIdx(vector<int>& nums, int begin, int end) {
    int idx = begin;
    for (int i = begin; i <= end; ++i) {
      if (nums[i] > nums[idx]) {
        idx = i;
      }
    }
    return idx;
  }
};
