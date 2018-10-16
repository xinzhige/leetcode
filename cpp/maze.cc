// DFS
class Solution {
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) {
      return true;
    }
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    return dfs(maze, visited, start[0], start[1],
               destination[0], destination[1]);
  }
  bool dfs(vector<vector<int>>& maze, vector<vector<int>>& visited,
           int i, int j, int di, int dj) {
    if (i == di && j == dj) {
      return true;
    }
    if (visited[i][j] != -1) {
      return visited[i][j] == 1 ? true : false;
    }
    bool result = false;
    int m = maze.size();
    int n = maze[0].size();
    maze[i][j] = -1;
    for (const auto& dir : dirs) {
      int x = i;
      int y = j;
      while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
        x += dir[0];
        y += dir[1];
      }
      x -= dir[0];
      y -= dir[1];
      if (maze[x][y] != -1) {
        result |= dfs(maze, visited, x, y, di, dj);
      }
    }
    visited[i][j] = (result ? 1 : 0);
    return result;
  }
private:
  vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
};


// BFS
class Solution {
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) {
      return true;
    }
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t.first == destination[0] && t.second == destination[1]) {
        return true;
      }
      for (const auto& dir : dirs) {
        int x = t.first;
        int y = t.second;
        while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
          x += dir[0];
          y += dir[1];
        }
        x -= dir[0];
        y -= dir[1];
        if (!visited[x][y]) {
          visited[x][y] = true;
          q.push({x, y});
        }
      }
    }
    return false;
  }
};
