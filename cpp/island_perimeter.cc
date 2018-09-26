class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int result = 0;
    int count = 0;
    int repeated = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          count += 1;
          if (i != 0 && grid[i-1][j] == 1) {
            repeated += 1;
          }
          if (j != 0 && grid[i][j-1] == 1) {
            repeated += 1;
          }
        }
      }
    }
    result = 4 * count - 2 * repeated;
    return result;
  }
};
