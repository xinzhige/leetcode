// Idea: search for lower bound and upper bound.
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result{-1, -1};
    int leftIndex = binarySearch(nums, target, true);
    // assert that leftIndex is within the array bounds and that
    // target is actually in nums.
    if (leftIndex == nums.size() || nums[leftIndex] != target) {
      return result;
    }
    result[0] = leftIndex;
    result[1] = binarySearch(nums, target, false) - 1;
    return result;
  }

  int binarySearch(vector<int>& nums, int target, bool left) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] > target || (left && target == nums[mid])) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
