// Note: the move is symmetric, for example, it can move from 0 to 4, 6
// and it can only move from 4, 6 to 0. The O(lgn) algorithm is written by
// Python.
class Solution {
public:
  int knightDialer(int N) {
    const int MOD = 1000000007;
    vector<vector<int>> moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},
                                 {},{0,1,7},{2,6},{1,3},{2,4}};
    vector<vector<int>> dp(2, vector<int>(10, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    int curr = 0;
    for (int i = 1; i < N; ++i) {
      curr = 1 - curr;
      for (int j = 0; j < 10; ++j) {
        dp[curr][j] = 0;
        for (const int p : moves[j]) {
          dp[curr][j] += dp[1 - curr][p];
          dp[curr][j] %= MOD;
        }
      }
    }
    int result = 0;
    for (const int x : dp[curr]) {
      result += x;
      result %= MOD;
    }
    return result;
  }
};
