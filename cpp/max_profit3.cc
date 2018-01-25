// for at most 2 transactions
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int prices_size = prices.size();
    if (prices_size == 0 || prices_size == 1) {
      return 0;
    }
    vector<int> history_profit(prices_size, 0);
    vector<int> future_profit(prices_size, 0);
    int valley = prices[0];
    int peak = prices[prices_size - 1];
    int max_profit = 0;
    // forward, calculate max profit until this time
    for (int i = 1; i < prices_size; ++i) {
      valley = min(valley, prices[i]);
      history_profit[i] = max(history_profit[i - 1], prices[i] - valley);
    }
    // backward, calculate max profit from now, and the sum with history
    for (int i = prices_size - 2; i >= 0; --i) {
      peak = max(peak, prices[i]);
      future_profit[i] = max(future_profit[i + 1], peak - prices[i]);
      max_profit = max(max_profit, history_profit[i] + future_profit[i]);
    }
    return max_profit;
  }
};

// at most k transactions
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    const int kNumTransaction = 3;
    int f[kNumTransaction] = {0};
    int g[kNumTransaction] = {0};
    int n = prices.size() - 1;
    for (int i = 0; i < n; ++i) {
      int diff = prices[i+1] - prices[i];
      int m = min(i+1, 2);
      for (int j = m; j >= 1; --j) {
	      f[j] = max(f[j], g[j-1]) + diff;
	g[j] = max(g[j], f[j]);
      }
    }
    return max(g[1], g[2]);
  }
};
