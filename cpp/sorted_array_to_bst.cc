class Solution {
public:
  TreeNode *SortedArrayToBSTHelper(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = begin + (end - begin) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = SortedArrayToBSTHelper(nums, begin, mid - 1);
    root->right = SortedArrayToBSTHelper(nums, mid + 1, end);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return SortedArrayToBSTHelper(nums, 0, nums.size() - 1);
  }
};
