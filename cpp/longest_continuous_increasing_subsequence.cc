class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int head = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i-1] >= nums[i]) {
        head = i;
      }
      result = max(result, i - head + 1);
    }
    return result;
  }
};
