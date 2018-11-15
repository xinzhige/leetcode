class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<double>> dp(N, vector<double>(N, 0.0));
    dp[r][c] = 1.0;
    for (; K > 0; --K) {
      vector<vector<double>> t(N, vector<double>(N, 0.0));
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          for (const auto &dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < N && y >= 0 && y < N) {
              t[i][j] += dp[x][y] / 8.0;
            }
          }
        }
      }
      dp = t;
    }
    double result = 0.0;
    for (const auto &row : dp) {
      for (const auto &x : row) {
        result += x;
      }
    }
    return result;
  }

private:
  vector<vector<int>> dirs{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                           {1, 2}, {2, 1}, {2, -1}, {1, -2}};
};
