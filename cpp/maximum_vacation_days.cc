/*
 * dp[i][j] stands for the max vacation days we can get in week i staying in
 * city j. It's obvious that dp[i][j] = max(dp[i - 1][k] + days[j][i])
 * (k = 0...N - 1, if we can go from city k to city j).
 * Also because values of week i only depends on week i - 1, so we can
 * compress two dimensional dp array to one dimension.
 */
class Solution {
public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    int n = flights.size();
    int k = days[0].size();
    vector<int> dp(n, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
      vector<int> temp(n, INT_MIN);
      for (int j = 0; j < n; ++j) {
        for(int k = 0; k < n; ++k) {
          if (j == k || flights[k][j] == 1) {
            temp[j] = max(temp[j], dp[k] + days[j][i]);
          }
        }
      }
      dp = temp;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
