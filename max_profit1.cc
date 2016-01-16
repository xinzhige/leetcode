// brute force
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int prices_size = prices.size();
    if (prices_size == 0 || prices_size == 1) {
      return 0;
    }
    int max_outer = 0;
    for (int i = prices_size-1; i > 0; --i) {
      int max_inner = 0;
      for (int j = i-1; j >= 0; --j) {
	int current_max_inner = prices[i] - prices[j];
	if (current_max_inner > max_inner) {
	  max_inner = current_max_inner;
	}
      }
      if (max_inner > max_outer) {
	max_outer = max_inner;
      }
    }
    return max_outer;
  }
};


// O(n)
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
