class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.size() == 0 || costs[0].empty()) {
      return 0;
    }
    auto min1 = 0;
    auto min2 = 0;
    auto idx1 = -1;
    for (auto i = 0; i < costs.size(); ++i) {
      auto m1 = INT_MAX;
      auto m2 = INT_MAX;
      auto id1 = -1;
      for (auto j = 0; j < costs[i].size(); ++j) {
        auto cost = costs[i][j] + (j == idx1 ? min2 : min1);
        if (cost < m1) {
          m2 = m1;
          m1 = cost;
          id1 = j;
        } else if (cost < m2) {
          m2 = cost;
        }
      }
      min1 = m1;
      min2 = m2;
      idx1 = id1;
    }
    return min1;
  }
};
