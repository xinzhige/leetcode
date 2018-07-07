// dp[n] = min{dp[n-i*i]+1}
class Solution {
public:
  int numSquares(int n) {
    vector<int> count({0});
    while (count.size() <= n) {
      int m = count.size();
      int nSquares = INT_MAX;
      for (int i = 1; i <= m / i; i++) {
        nSquares = min(nSquares, count[m - i*i] + 1);
      }
      count.push_back(nSquares);
    }
    return count[n];
  }
};
