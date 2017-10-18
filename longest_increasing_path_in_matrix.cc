class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    m = matrix.size();
    n = matrix[0].size();
    vector<vector<int>> cache(m, vector<int>(n, 0));
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = max(result, dfs(matrix, i, j, cache));
      }
    }
    return result;
  }

  int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
    if (cache[i][j] > 0) {
      return cache[i][j];
    }
    for (auto &dir : dirs) {
      int x = i + dir[0];
      int y = j + dir[1];
      if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
        cache[i][j] = max(cache[i][j], dfs(matrix, x, y, cache));
      }
    }
    cache[i][j] += 1;
    return cache[i][j];
  }

private:
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int m;
  int n;
};
