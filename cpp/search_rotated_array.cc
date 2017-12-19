class Solution {
public:
  int search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (begin <= end) {
      mid = begin + (end - begin) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[begin] <= nums[mid]) {
        // 1. If nums[begin] <= nums[mid] then the begin part must be sorted is
        // because a. if pivot is in between begin and mid, then nums[begin]
        // must be larger than nums[mid], which is contradictory with
        // the condition. b. if pivot is not in between, then the begin part
        // is clearly sorted.
        // 2. To decide if target is in between begin and mid, for example,
        // 4 5 6 7 0 1 2, begin=0, mid=3, target=1, then nums[begin] <= target is needed.
        if (nums[begin] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          begin = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[end]) {
          begin = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return -1;
  }
};
