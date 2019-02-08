// By 2d array
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      grid[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      grid[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
      }
    }
    return grid[m - 1][n - 1];
  }
};

// By array
class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m < n) {
      swap(m, n);
    }
    vector<int> path(n, 1);
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        path[j] += path[j - 1];
      }
    }
    return path[n - 1];
  }
};
