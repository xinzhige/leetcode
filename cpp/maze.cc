// DFS
class Solution {
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) {
      return true;
    }
    m = maze.size();
    n = maze[0].size();
    return backtrack(maze, start[0], start[1],
                     destination[0], destination[1]);
  }
  bool backtrack(vector<vector<int>>& maze, int i, int j, int di, int dj) {
    if (i == di && j == dj) {
      return true;
    }
    bool result = false;
    for (const auto &dir : dirs) {
      int x = i;
      int y = j;
      while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
        x += dir[0];
        y += dir[1];
      }
      x -= dir[0];
      y -= dir[1];
      if (maze[x][y] == 0) {
        maze[x][y] = 2;
        result |= backtrack(maze, x, y, di, dj);
      }
    }
    return result;
  }

private:
  vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
  int m = 0;
  int n = 0;
};


// BFS, key: the ball can only roll in one direction.
class Solution {
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) {
      return true;
    }
    int m = maze.size();
    int n = maze[0].size();
    queue<pair<int, int>> ends;
    ends.emplace(start[0], start[1]);
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[start[0]][start[1]] = 1;
    while (!ends.empty()) {
      auto t = ends.front();
      ends.pop();
      if (t.first == destination[0] && t.second == destination[1]) {
        return true;
      }
      for (const auto& dir : dirs) {
        int x = t.first;
        int y = t.second;
        while (x >= 0 && x < m && y >= 0 && y < n &&
               maze[x][y] == 0) {
          x += dir[0];
          y += dir[1];
        }
        x -= dir[0];
        y -= dir[1];
        if (visited[x][y] == 0) {
          visited[x][y] = 1;
          ends.push({x, y});
        }
      }
    }
    return false;
  }
};
