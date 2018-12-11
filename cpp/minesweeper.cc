class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board.empty() || board[0].empty()) {
      return {};
    }
    int m = board.size();
    int n = board[0].size();
    int row = click[0];
    int col = click[1];
    int count = 0;
    if (board[row][col] == 'M') {
      board[row][col] = 'X';
    } else {
      vector<vector<int>> neighbors;
      for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
          int x = row + i;
          int y = col + j;
          if (x >= 0 && x < m && y >= 0 && y < n) {
            if (board[x][y] == 'M') {
              count += 1;
            } else if (count == 0 && board[x][y] == 'E') {
              neighbors.push_back({x, y});
            }
          }
        }
      }
      if (count > 0) {
        board[row][col] = '0' + count;
      } else {
        for (auto &nei : neighbors) {
          board[nei[0]][nei[1]] = 'B';
          updateBoard(board, nei);
        }
      }
    }
    return board;
  }
};
