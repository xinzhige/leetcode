class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
      for (int j = 0; j < rooms[i].size(); ++j) {
        if (rooms[i][j] == 0) {
          dfs(rooms, i, j, 0);
        }
      }
    }
  }
  void dfs(vector<vector<int>> &rooms, int i, int j, int val) {
    if (i >= 0 && i < rooms.size() && j >= 0 &&
        j < rooms[i].size() && rooms[i][j] >= val) {
      rooms[i][j] = val;
      for (const auto &d : dirs) {
        dfs(rooms, i + d[0], j + d[1], val + 1);
      }
    }
  }
private:
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
