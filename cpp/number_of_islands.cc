// DFS
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    if (m == 0) {
      return 0;
    }
    n = grid[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          result += 1;
          dfs(grid, i, j);
        }
      }
    }
    return result;
  }
  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    for (const auto &dir : dirs) {
      dfs(grid, i + dir[0], j + dir[1]);
    }
  }
private:
  vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m = 0;
  int n = 0;
};


// BFS
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    if (m == 0) {
      return 0;
    }
    n = grid[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          result += 1;
          bfs(grid, i, j);
        }
      }
    }
    return result;
  }
  void bfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';
    queue<pair<int, int>> neighbors;
    neighbors.emplace(i, j);
    while (!neighbors.empty()) {
      const auto neighbor = neighbors.front();
      neighbors.pop();
      int x = neighbor.first;
      int y = neighbor.second;
      if (x >= 1 && grid[x-1][y] == '1') {
        neighbors.emplace(x-1, y);
        grid[x-1][y] = '0';
      }
      if (x < m - 1 && grid[x+1][y] == '1') {
        neighbors.emplace(x+1, y);
        grid[x+1][y] = '0';
      }
      if (y >= 1 && grid[x][y-1] == '1') {
        neighbors.emplace(x, y-1);
        grid[x][y-1] = '0';
      }
      if (y < n - 1 && grid[x][y+1] == '1') {
        neighbors.emplace(x, y+1);
        grid[x][y+1] = '0';
      }
    }
  }
private:
  int m = 0;
  int n = 0;
};
