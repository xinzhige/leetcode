/*
 * Idea: think of each state of the board as a string and "123450" is the
 * target. So, the problem becomes how to find the length of short path
 * from current state to the target (BFS).
 * Key: build a direction array that 0 can go, where the value is the index
 * of neighbors of 0 in string.
 */
class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    if (board.empty() || board[0].empty()) {
      return -1;
    }
    string target = "123450";
    string start = "";
    for (const auto &row : board) {
      for (const int &x : row) {
        start += x + '0';
      }
    }
    vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5},
                                {0, 4}, {1, 3, 5}, {2, 4}};
    set<string> visited;
    visited.insert(start);
    queue<string> q;
    q.push(start);
    int result = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string cur = q.front();
        q.pop();
        if (cur == target) {
          return result;
        }
        int zero = cur.find_first_of('0');
        for (int dir : dirs[zero]) {
          string next = cur;
          swap(next[zero], next[dir]);
          if (visited.count(next) == 0) {
            visited.insert(next);
            q.push(next);
          }
        }
      }
      result += 1;
    }
    return -1;
  }
};
