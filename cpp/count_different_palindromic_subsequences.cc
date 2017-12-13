class Solution {
public:
  int countPalindromicSubsequences(string S) {
    size_t n = S.size();
    const int base = 1000000007;
    auto dp_ptr = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n, 0)));
    auto &dp = *dp_ptr;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          char c = 'a' + k;
          if (j == i) {
            if (S[i] == c) {
              dp[k][i][j] = 1;
            } else {
              dp[k][i][j] = 0;
            }
          } else {
            if (S[i] != c) {
              dp[k][i][j] = dp[k][i+1][j];
            } else if (S[j] != c) {
              dp[k][i][j] = dp[k][i][j-1];
            } else {
              dp[k][i][j] = 2;
              if (j > i + 1) {
                for (int m = 0; m < 4; ++m) {
                  dp[k][i][j] += dp[m][i+1][j-1];
                  dp[k][i][j] %= base;
                }
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int k = 0; k < 4; ++k) {
      ans += dp[k][0][n-1];
      ans %= base;
    }
    return ans;
  }
};
