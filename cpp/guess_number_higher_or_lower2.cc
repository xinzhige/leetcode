// Idea: in range [i, j], pick the pivot p such that it minimizes
// p + max(dp[i][p-1], dp[p+1][j]).
// Note: choose pivot that is in [(i+j)/ 2, j] because the cost of
// right side is larger than the left one.
class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; ++len) {
      for (int start = 1; start <= n - len + 1; ++start) {
        int min_res = INT_MAX;
        for (int piv = start + (len - 1) / 2; piv < start + len - 1; ++piv) {
          int res = piv + max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
          min_res = min(res, min_res);
        }
        dp[start][start + len - 1] = min_res;
      }
    }
    return dp[1][n];
  }
};
