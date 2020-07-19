class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int price : prices) {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + price);
            dp_i_1 = max(dp_i_1, tmp - price - fee);
        }
        return dp_i_0; 
    }
};
