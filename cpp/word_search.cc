// Backtracking
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (backtrack(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
private:
  bool backtrack(vector<vector<char>> &board, const string &word,
                 int level, int i, int j) {
    if (level == word.size()) {
      return true;
    }
    bool result = false;
    if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == word[level]) {
      board[i][j] = '#';
      for (const auto &dir : dirs) {
        result = result || backtrack(board, word, level + 1,
                                     i + dir[0], j + dir[1]);
      }
      board[i][j] = word[level];
    }
    return result;
  }

private:
  vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int m = 0;
  int n = 0;
};
