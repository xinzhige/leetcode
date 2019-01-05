class Solution {
public:
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball,
                         vector<int>& hole) {
    pair<string, int> res = {"impossible", INT_MAX};
    return roll(maze, ball, hole, 0, 0, 0, "", res);
  }
  string roll(vector<vector<int>>& maze, vector<int> ball,
              const vector<int>& hole, int d_row, int d_col,
              int steps, const string &path, pair<string, int> &res) {
    if (steps < res.second) {
      if (d_row != 0 || d_col != 0) {
        while (ball[0] + d_row >= 0 &&
               ball[1] + d_col >= 0 &&
               ball[0] + d_row <  maze.size() &&
               ball[1] + d_col < maze[0].size() &&
               maze[ball[0] + d_row][ball[1] + d_col] != 1) {
          ball[0] += d_row;
          ball[1] += d_col;
          steps += 1;
          if (ball[0] == hole[0] && ball[1] == hole[1] && steps < res.second) {
            res = {path, steps};
          }
        }
      }
      if (maze[ball[0]][ball[1]] == 0 || steps + 2 < maze[ball[0]][ball[1]]) {
        maze[ball[0]][ball[1]] = steps + 2;
        if (d_row == 0) roll(maze, ball, hole, 1, 0, steps, path + "d", res);
        if (d_col == 0) roll(maze, ball, hole, 0, -1, steps, path + "l", res);
        if (d_col == 0) roll(maze, ball, hole, 0, 1, steps, path + "r", res);
        if (d_row == 0) roll(maze, ball, hole, -1, 0, steps, path + "u", res);
      }
    }
    return res.first;
  }
};
