/*
 * Idea: dynamic programming, dp[i][j] represents if s[0:i) and p[0:j) match.
 * dp[i][j] = dp[i - 1][j - 1],
 * if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
 * dp[i][j] = dp[i][j - 2],
 * if p[j - 1] == '*' and the pattern repeats for 0 time;
 * dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'),
 * if p[j - 1] == '*' and the pattern repeats for at least 1 time.
*/
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= m; i++) {
      // pre is used as dp[i-1][j-1].
      int pre = dp[0];
      dp[0] = (i == 0 ? 1 : 0);
      for (int j = 1; j <= n; ++j) {
        int temp = dp[j];
        // '*' can't be the first letter of p so j > 1 if p[j-1]=='*'.
        if (p[j - 1] == '*') {
          dp[j] = ((dp[j - 2] == 1) ||
                   (dp[j] == 1 &&
                    i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')));
        } else {
          dp[j] = (pre == 1 &&
                   i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
        }
        pre = temp;
      }
    }
    return dp[n] == 1;
  }
};
