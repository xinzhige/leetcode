class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int currMax = INT_MIN;
    int secondMax = INT_MIN;
    int index = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (currMax < nums[i]) {
        secondMax = currMax;
        currMax = nums[i];
        index = i;
      }
      if (nums[i] < currMax && nums[i] > secondMax) {
        secondMax = nums[i];
      }
    }
    if (currMax >= 2*secondMax) {
      return index;
    } else {
      return -1;
    }
  }
};
