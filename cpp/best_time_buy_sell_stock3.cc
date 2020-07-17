class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i10 = 0;
        int dp_i11 = INT_MIN;
        int dp_i20 = 0;
        int dp_i21 = INT_MIN;
        for (int price : prices) {
            dp_i20 = max(dp_i20, dp_i21 + price);
            dp_i21 = max(dp_i21, dp_i10 - price);
            dp_i10 = max(dp_i10, dp_i11 + price);
            dp_i11 = max(dp_i11, -price);
        }
        return dp_i20;
    }
};
