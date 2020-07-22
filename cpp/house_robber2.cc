// the first and last elements can not be included at the same time
// so the array can be divided into 0...n-2 and 1...n-1.
class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0]; 
    }
    return max(rob_helper(nums, 0, n - 2), rob_helper(nums, 1, n - 1));
  }

  int rob_helper(vector<int>& nums, int left, int right) {
    int prev_max = 0; 
    int cur_max = 0;
    for (int i = left; i <= right; i++) {
      int curr = max(cur_max, prev_max + nums[i]);
      prev_max = cur_max;
      cur_max = curr;
    }
    return cur_max;
  }
};
