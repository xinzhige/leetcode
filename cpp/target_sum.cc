class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int s) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum < s) || ((s + sum) & 1)) {
      return 0;
    } else {
      return subsetSum(nums, (s + sum) >> 1); 
    }
  }   

private:
  int subsetSum(vector<int>& nums, int s) {
    vector<int> dp(s+1, 0);
    dp[0] = 1;
    for (const auto & n : nums) {
      for (int i = s; i >= n; i--) {
	    dp[i] += dp[i - n];
      }
    }
    return dp[s];
  }
};
