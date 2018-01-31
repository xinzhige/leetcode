class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        swap(currMax, currMin);
      }
      currMax = max(nums[i], nums[i] * currMax);
      currMin = min(nums[i], nums[i] * currMin);
      result = max(currMax, result);
    }
    return result;
  }
};
