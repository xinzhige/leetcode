// Time: O(n^2), space: O(n)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    int result = 1;
    for (int i = 1; i < n; ++i) {
      int maxLen = 0;
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          maxLen = max(maxLen, dp[j]);
        }
      }
      dp[i] = maxLen + 1;
      result = max(result, dp[i]);
    }
    return result;
  }
};


// Time: O(nlgn), space: O(n)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); ++i) {
      int left = 0;
      int right = dp.size();
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] < nums[i]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      if (right >= dp.size()) {
        dp.push_back(nums[i]);
      } else {
        dp[right] = nums[i];
      }
    }
    return dp.size();
  }
};
