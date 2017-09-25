class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) {
      return INT_MIN;
    }
    int result = nums[0];
    int curr_max = nums[0];
    int curr_min = nums[0];
    for (int i = 1; i < len; ++i) {
      int tmp = curr_max;
      curr_max = max(max(nums[i] * curr_max, nums[i]), nums[i] * curr_min);
      curr_min = min(min(nums[i] * tmp, nums[i]), nums[i] * curr_min);
      result = max(curr_max, result);
    }
    return result;
  }
};
