class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int price : prices) {
            dp_i_0 = max(dp_i_0, dp_i_1 + price);
            dp_i_1 = max(dp_i_1, -price);
        }
        return dp_i_0; 
    }
};
