// DFS
class Solution {
public:
  int numDistinctIslands(vector<vector<int>>& grid) {
    m = grid.size();
    if (m == 0) {
      return 0;
    }
    n = grid[0].size();
    set<vector<pair<int, int>>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> p;
          dfs(grid, i, j, i, j , p);
          result.insert(p);
        }
      }
    }
    return result.size();
  }
  void dfs(vector<vector<int>> &grid, int x0, int y0, int i, int j,
           vector<pair<int, int>> &pos) {
    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] > 0) {
      grid[i][j] *= -1;
      pos.emplace_back(i - x0, j - y0);
      for (const auto &dir : dirs) {
        dfs(grid, x0, y0, i + dir[0], j + dir[1], pos);
      }
    }
  }
private:
  vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  int m = 0;
  int n = 0;
};


// BFS
class Solution {
public:
  int numDistinctIslands(vector<vector<int>>& grid) {
    m = grid.size();
    if (m == 0) {
      return 0;
    }
    n = grid[0].size();
    set<vector<pair<int, int>>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> pos;
          queue<pair<int, int>> q;
          q.emplace(i, j);
          grid[i][j] *= -1;
          while (!q.empty()) {
            const auto t = q.front();
            q.pop();
            for (const auto &dir : dirs) {
              int x = t.first + dir[0];
              int y = t.second + dir[1];
              if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                q.emplace(x, y);
                grid[x][y] *= -1;
                pos.emplace_back(x - i, y - j);
              }
            }
          }
          result.insert(pos);
        }
      }
    }
    return result.size();
  }
private:
  vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  int m = 0;
  int n = 0;
};
