class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_index = 0;
        int max_diff = 0;
        //int buy = 0;
        //int sell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < prices[min_index]) {
                min_index = i;
            }
            int current_diff = prices[i] - prices[min_index];
            if (current_diff > max_diff) {
                //buy = min_index;
                //sell = i;
                max_diff = current_diff;
            }
        }
        return max_diff;
    }
};
