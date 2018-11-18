// Time (TLE): O(n*m^2), space: O(nm)
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 0; j <= amount; ++j) {
        dp[i][j] = 0;
        for (int k = 0; k * coins[i - 1] <= j; ++k) {
          dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
        }
      }
    }
    return dp[coins.size()][amount];
  }
};


// Time: O(mm), space: O(mn)
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); ++i) {
      for (int j = 0; j <= amount; ++j) {
        dp[i][j] = dp[i - 1][j] +
          (coins[i - 1] <= j ? dp[i][j - coins[i - 1]] : 0);
      }
    }
    return dp[coins.size()][amount];
  }
};



// Time: O(mn), space: O(m)
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const auto &coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        dp[i] += dp[i - coin];
      }
    }
    return dp[amount];
  }
};
