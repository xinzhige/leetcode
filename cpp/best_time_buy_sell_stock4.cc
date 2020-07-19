class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (k >= len / 2) {
            return quick_solve(prices);
        }
        vector<vector<int>> dp(k + 1, vector<int>(len, 0));
        for (int i = 1; i <= k; i++) {
            int tmp_max =  -prices[0];
            for (int j = 1; j < len; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + tmp_max);
                tmp_max =  max(tmp_max, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][len - 1];
    }

private: int quick_solve(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        for (int i = 1; i < len; i++)
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        return profit;
    }
};
