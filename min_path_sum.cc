// method 1, time: O(m*n), space: O(m*n)
class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > matrix(m, vector<int> (n));
    if (m == 0 || n == 0) {
      return grid[0][0];
    } else {
      matrix[0][0] = grid[0][0];
    }
    for (int i = 1; i < m; ++i) {
      matrix[i][0] = matrix[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
      matrix[0][j] = matrix[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
	matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + grid[i][j];
      }
    }
    return matrix[m-1][n-1];
  }
};

// method 2, time: O(m*n), space: O(min(m,n))
class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    vector<int> curr_row(n, INT_MAX);
    curr_row[0] = 0;
    for (int i = 0; i < m; ++i) {
      curr_row[0] += grid[i][0];
      for (int j = 1; j < n; ++j) {
	curr_row[j] = min(curr_row[j], curr_row[j-1]) + grid[i][j];
      }
    }
    return curr_row.back();
  }
};
