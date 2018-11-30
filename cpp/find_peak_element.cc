// Idea: compare the element with its right neighbor to check whether the
// local sequence is ascending or descending.
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] > nums[mid + 1]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};
