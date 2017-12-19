class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (begin <= end) {
      mid = begin + (end - begin) / 2;
      if (nums[mid] == target) {
        return true;
      } else if (nums[begin] < nums[mid]) {   // The left half is sorted
        if (nums[begin] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          begin = mid + 1;
        }
      } else if (nums[begin] > nums[mid]) { // The right half is sorted
        if (nums[mid] < target && target <= nums[end]) {
          begin = mid + 1;
        } else {
          end = mid - 1;
        }
      } else {
        // We dont know what the situation is on the left part, for example, {3, 3, 3, 3, 0, 1, 2} or {3, 4, 5, 6, 3, 3, 3, 3, 3}
        begin += 1;
      }
    }
    return false;
  }
};
