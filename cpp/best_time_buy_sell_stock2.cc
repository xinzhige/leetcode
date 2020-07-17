class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, tmp -prices[i]);
        }
        return dp_i_0; 
    }
};
