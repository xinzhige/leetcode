// DP, for each value from 1 to amount, compute minimum coins needed.
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const int &x: coins) {
        if (x <= i) {
          dp[i] = min(dp[i], dp[i - x] + 1);
        }
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
