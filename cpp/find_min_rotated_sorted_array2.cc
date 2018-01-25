class Solution {
public:
  int findMin(vector<int> &nums) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (begin < end && nums[begin] >= nums[end]) {
      mid = begin + (end - begin) / 2;
      if (nums[mid] > nums[end]) {
        begin = mid + 1;
      } else if (nums[mid] < nums[begin]) {
        end = mid;
      } else {
        begin += 1;
      }
    }
    return nums[begin];
  }
};
