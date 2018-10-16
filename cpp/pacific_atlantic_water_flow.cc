// DFS
class Solution {
public:
   vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    vector<pair<int, int>> result;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      dfs(matrix, i, 0, INT_MIN, pacific);
      dfs(matrix, i, n - 1, INT_MIN, atlantic);
    }
    for (int j = 0; j < n; ++j) {
      dfs(matrix, 0, j, INT_MIN, pacific);
      dfs(matrix, m - 1, j, INT_MIN, atlantic);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }
  void dfs(vector<vector<int>>& matrix, int i, int j, int prev,
           vector<vector<bool>> &visited) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
        matrix[i][j] < prev) {
      return;
    }
    visited[i][j] = true;
    dfs(matrix, i + 1, j, matrix[i][j], visited);
    dfs(matrix, i - 1, j, matrix[i][j], visited);
    dfs(matrix, i, j - 1, matrix[i][j], visited);
    dfs(matrix, i, j + 1, matrix[i][j], visited);
  }
};


// BFS
class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    vector<pair<int, int>> result;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    for (int i = 0; i < m; ++i) {
      q1.push({i, 0});
      q2.push({i, n - 1});
      pacific[i][0] = true;
      atlantic[i][n-1] = true;
    }
    for (int j = 0; j < n; ++j) {
      q1.push({0, j});
      q2.push({m - 1, j});
      pacific[0][j] = true;
      atlantic[m-1][j] = true;
    }
    bfs(matrix, q1, pacific);
    bfs(matrix, q2, atlantic);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }
  void bfs(vector<vector<int>>& matrix, queue<pair<int, int>> &q,
           vector<vector<bool>> &visited) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dirs{{0, -1},{-1, 0},{0, 1},{1, 0}};
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      for (const auto &dir : dirs) {
        int x = curr.first + dir[0];
        int y = curr.second + dir[1];
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            matrix[x][y] < matrix[curr.first][curr.second]) {
          continue;
        }
        visited[x][y] = true;
        q.push({x, y});
      }
    }
  }
};
