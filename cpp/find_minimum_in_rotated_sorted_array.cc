// Idea: find min begin s.t. nums[begin] < nums[begin + 1].
class Solution {
public:
  int findMin(vector<int> &num) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin < end && nums[begin] > nums[end]) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] < nums[begin]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return nums[begin];
  }
};
