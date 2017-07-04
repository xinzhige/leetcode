class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0; 
    }
    if (n == 1) {
      return nums[0]; 
    }
    return max(rob_helper(nums, 0, n - 2), rob_helper(nums, 1, n - 1));
  }

  int rob_helper(vector<int>& nums, int left, int right) {
    int prev_max = 0; 
    int curr_max = 0;
    for (int i = left; i <= right; i++) {
      int curr = max(curr_max, prev_max + nums[i]);
      prev_max = curr_max;
      curr_max = curr;
    }
    return curr_max;
  }
};
