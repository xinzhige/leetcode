// 2D dp
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i+1][j-1] + 2;
        } else {
          dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
      }
    }
    return dp[0][n-1];
  }
};

// 1D DP
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    int result = 0;
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; --i) {
      int len = 0;
      for (int j = i + 1; j < n; ++j) {
        int t = dp[j];
        if (s[i] == s[j]) {
          dp[j] = len + 2;
        }
        len = max(len, t);
      }
    }
    for (int num : dp) {
      result = max(result, num);
    }
    return result;
  }
};
