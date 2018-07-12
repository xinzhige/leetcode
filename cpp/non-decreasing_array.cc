class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    bool modified = false;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < prev) {
        if (modified) {
          return false;
        } else {
          modified = !modified;
        }
      }
      if (nums[i] >= prev || i < 2 || nums[i - 2] <= nums[i]) {
        prev = nums[i];
      }
    }
    return true;
  }
};
