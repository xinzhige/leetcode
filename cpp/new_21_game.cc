class Solution {
public:
  double new21Game(int N, int K, int W) {
    vector<double> dp(N + W + 1, 0.0);
    fill(dp.begin() + K, dp.begin() + N + 1, 1.0);
    // Initially, s is the sum of window (length W) on the right side of K - 1.
    double s = min(N - K + 1, W);
    for (int k = K - 1; k >= 0; --k) {
      dp[k] = s / W;
      s += dp[k] - dp[k + W];
    }
    return dp[0];
  }
};
