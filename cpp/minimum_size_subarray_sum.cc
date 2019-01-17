// Idea: two pointers point to the begin and the end of current subarray,
// every time increment the end and decrease the begin until the sum is
// less than s.
// Time: O(n), because each element at most visited twice.
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (sum >= s) {
        result = min(result, i - left + 1);
        sum -= nums[left];
        left += 1;
      }
    }
    return result == INT_MAX ? 0 : result;
  }
};
