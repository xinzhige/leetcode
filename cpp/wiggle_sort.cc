// Idea: compare current number nums[i] with the previous one nums[i-1],
// 1. if odd position and nums[i] < nums[i-1] or
// 2. even position and nums[i] >= nums[i-1], swap them.
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if ((i % 2 != 0) == (nums[i - 1] > nums[i])) {
        swap(nums[i - 1], nums[i]);
      }
    }
  }
};
