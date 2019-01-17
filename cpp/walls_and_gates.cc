// Idea: from each 0, search its neighbors and update distance.
class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty() || rooms[0].empty()) {
      return;
    }
    m = rooms.size();
    n = rooms[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          dfs(rooms, i, j, 0);
        }
      }
    }
  }
  void dfs(vector<vector<int>> &rooms, int i, int j, int dist) {
    if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] >= dist) {
      rooms[i][j] = dist;
      for (const auto &d : dirs) {
        dfs(rooms, i + d[0], j + d[1], dist + 1);
      }
    }
  }
private:
  const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int m = 0;
  int n = 0;
};
