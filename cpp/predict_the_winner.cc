// Idea: dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
// Note: in dp, only the next row i+1, the same column j and the previous
// column j-1, the same row i are needed. We can calculate dp from the end
// of the array to make sure dp[i+1][j] can be calculated before dp[i][j].
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int s = n - 2; s >= 0; --s) {
      for (int e = s + 1; e < n; ++e) {
        int a = nums[s] - dp[e];
        int b = nums[e] - dp[e - 1];
        dp[e] = max(a, b);
      }
    }
    return dp[n - 1] >= 0;
  }
};
