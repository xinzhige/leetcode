// Space: O(mn)
class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int result = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> v1(m, vector<int>(n, 0));
    vector<vector<int>> v2 = v1;
    vector<vector<int>> v3 = v1;
    vector<vector<int>> v4 = v1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int t = ((j == 0 || grid[i][j] == 'W') ? 0 : v1[i][j-1]);
        v1[i][j] = (grid[i][j] == 'E' ? t + 1: t);
      }
      for (int j = n - 1; j >= 0; --j) {
        int t = ((j == n - 1 || grid[i][j] == 'W') ? 0 : v2[i][j+1]);
        v2[i][j] = (grid[i][j] == 'E' ? t + 1: t);
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        int t = ((i == 0 || grid[i][j] == 'W') ? 0 : v3[i-1][j]);
        v3[i][j] = (grid[i][j] == 'E' ? t + 1: t);
      }
      for (int i = m - 1; i >= 0; --i) {
        int t = ((i == m - 1 || grid[i][j] == 'W') ? 0 : v4[i+1][j]);
        v4[i][j] = (grid[i][j] == 'E' ? t + 1: t);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          result = max(result, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
        }
      }
    }
    return result;
  }
};



