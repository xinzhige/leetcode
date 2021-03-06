// Idea: the effective score for the current player only depends on
// the elements within the current range [i, j]. Let dp[i][j] be the
// effective score for the range [i, j],
// dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
// Note: in dp, only the next row i+1, the same column j and the previous
// column j-1 and the same row i are needed. We build dp from the end of
// the array to make sure dp[i+1][j] can be calculated before dp[i][j].
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        int a = nums[i] - dp[j];
        int b = nums[j] - dp[j - 1];
        dp[j] = max(a, b);
      }
    }
    return dp[n - 1] >= 0;
  }
};
