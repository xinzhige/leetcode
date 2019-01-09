// DFS
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    m = grid.size();
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
    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1') {
      grid[i][j] = '0';
      for (const auto &dir : dirs) {
        dfs(grid, i + dir[0], j + dir[1]);
      }
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
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    m = grid.size();
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
    queue<pair<int, int>> q;
    q.emplace(i, j);
    while (!q.empty()) {
      auto neighbor = q.front();
      q.pop();
      for (const auto &dir : dirs) {
        int x = neighbor.first + dir[0];
        int y = neighbor.second + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
          q.emplace(x, y);
          grid[x][y] = '0';
        }
      }
    }
  }
private:
  int m = 0;
  int n = 0;
};


// Union find
class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent.push_back(i * n + j);
            count += 1;
          } else {
            parent.push_back(-1);
          }
          rank.push_back(0);
        }
    }
  }

  int find(int i) { // path compression
    while (parent[i] != i) {
      i = parent[parent[i]];
    }
    return i;
  }

  void runUnion(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
      } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
      } else {
        parent[rooty] = rootx;
        rank[rootx] += 1;
      }
      count -= 1;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    UnionFind uf(grid);
    int num_islands = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          grid[i][j] = '0';
          for (const auto &dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n &&
                grid[x][y] == '1') {
              uf.runUnion(i * n + j, x * n + y);
            }
          }
        }
      }
    }
    return uf.getCount();
  }
private:
  vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
