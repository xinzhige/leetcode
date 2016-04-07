class Solution {
public:
  static bool greater(int i,int j) { return i > j; }
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater);
    return nums[k-1];
  }
};
