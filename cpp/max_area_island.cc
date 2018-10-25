// Backtracking
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int area = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int count = 0;
          backtracking(grid, i, j, count, area);
        }
      }
    }
    return area;
  }
  void backtracking(vector<vector<int>>& grid, int i, int j, int& count,
                    int& area) {
    if (i == -1 || i == m || j == -1 || j == n || grid[i][j] != 1) {
      return;
    }
    area = max(area, count + 1);
    count += 1;
    grid[i][j] *= -1;
    for (const auto &dir : dirs) {
      backtracking(grid, i + dir[0], j + dir[1], count, area);
    }
  }
private:
  vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int m = 0;
  int n = 0;
};


// BFS
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int area = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int count = 0;
          queue<pair<int, int>> q;
          q.emplace(i, j);
          grid[i][j] *= -1;
          while (!q.empty()) {
            auto t = q.front();
            q.pop();
            area = max(area, count + 1);
            count += 1;
            for (const auto& dir : dirs) {
              int x = t.first + dir[0];
              int y = t.second + dir[1];
              if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                grid[x][y] *= -1;
                q.emplace(x, y);
              }
            }
          }
        }
      }
    }
    return area;
  }
private:
  vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int m = 0;
  int n = 0;
};
