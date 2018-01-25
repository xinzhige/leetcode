class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int max_sum = 0;
    int prices_size = prices.size();
    for(int i = 1; i < prices_size; ++i) {
      int diff = prices[i] - prices[i-1];
      if(diff > 0) {
	max_sum += diff;
      }
    }
    return max_sum;
  }
};
