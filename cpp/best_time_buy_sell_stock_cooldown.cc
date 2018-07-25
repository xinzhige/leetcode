// Space: O(n)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    // Note: the buy must be initilized to be minimum such that
    // the first buy can be made
    dp[0][0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = max(dp[i-1][2] - prices[i-1], dp[i-1][0]);
      dp[i][1] = max(dp[i-1][0] + prices[i-1], dp[i-1][1]);
      dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
    }
    return dp[n][1];
  }
};



// Space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = INT_MIN;
    int sell = 0;
    int prev_sell = 0;
    int prev_buy = 0;
    for (const auto &p : prices) {
      prev_buy = buy;
      buy = max(prev_sell - p, buy);
      prev_sell = sell;
      sell = max(prev_buy + p, sell);
    }
    return sell;
  }
};
