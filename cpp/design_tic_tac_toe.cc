// Idea: use positive value and negative value to represent player 1 and
// player 2. If rows[0] == N, then player 1 has won because the first row
// is occupied by him. It is also applied to cols, diag and anti_diag.
class TicTacToe {
public:
  /** Initialize your data structure here. */
  TicTacToe(int n): N(n), diag(0), anti_diag(0) {
    rows.resize(n);
    cols.resize(n);
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
      0: No one wins.
      1: Player 1 wins.
      2: Player 2 wins. */

  int move(int row, int col, int player) {
    int add = (player == 1 ? 1 : -1);
    rows[row] += add;
    cols[col] += add;
    diag += (row == col ? add : 0);
    anti_diag += (row == N - col - 1 ? add : 0);
    return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N ||
            abs(anti_diag) == N) ? player : 0;
  }

private:
  vector<int> rows;
  vector<int> cols;
  int diag;
  int anti_diag;
  int N;
};
