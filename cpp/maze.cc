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
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[start[0]][start[1]] = true;
    while (!ends.empty()) {
      auto t = ends.front();
      ends.pop();
      if (t.first == destination[0] && t.second == destination[1]) {
        return true;
      }
      for (const auto& dir : dirs) {
        int x = t.first;
        int y = t.second;
        while (x + dir[0] >= 0 && x + dir[0] < m &&
               y + dir[1] >= 0 && y + dir[1]  < n &&
               maze[x + dir[0]][y + dir[1] ] == 0) {
          x += dir[0];
          y += dir[1];
        }
        if (!visited[x][y]) {
          visited[x][y] = true;
          ends.push({x, y});
        }
      }
    }
    return false;
  }
};
