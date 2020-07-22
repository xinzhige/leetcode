// space: O(n)
class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = max(dp[i+1], dp[i+2] + nums[i]);
    }
    return dp[0];
  }
};

// space: O(1)
class Solution {
public:
  int rob(vector<int>& nums) {
    int prev_max = 0;
    int curr_max = 0;
    for (int value : nums) {
      int curr_value = max(curr_max, prev_max + value);
      prev_max = curr_max;
      curr_max = curr_value;
    }
    return curr_max;
  }
};
