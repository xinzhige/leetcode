// By a matrix
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      matrix[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      matrix[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
      }
    }
    return matrix[m - 1][n - 1];
  }
};

// By a vector
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> path(n, 1);
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        path[j] += path[j - 1];
      }
    }
    return path[n - 1];
  }
};
