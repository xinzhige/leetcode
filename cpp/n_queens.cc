// Backtracking + Bitmask
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> nQueens(n, string(n, '.'));
    vector<int> flag_col(n, 1);
    vector<int> diagonal(2 * n - 1, 1);
    vector<int> anti_diagonal(2 * n - 1, 1);
    solveNQueens(n, 0, nQueens, flag_col, diagonal, anti_diagonal, result);
    return result;
  }
private:
  void solveNQueens(const int &n, int row, vector<string> &nQueens,
                    vector<int> &flag_col, vector<int> &diagonal,
                    vector<int> &anti_diagonal,
                    vector<vector<string>> &result) {
    if (row == n) {
      result.push_back(nQueens);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (flag_col[col] == 1 &&
          diagonal[n - 1 - row + col] == 1 &&
          anti_diagonal[row + col] == 1) {
        flag_col[col] = 0;
        diagonal[n - 1 - row + col] = 0;
        anti_diagonal[row + col] = 0;
        nQueens[row][col] = 'Q';
        solveNQueens(n, row + 1, nQueens, flag_col, diagonal, anti_diagonal,
                     result);
        nQueens[row][col] = '.';
        flag_col[col] = 1;
        diagonal[n - 1 - row + col] = 1;
        anti_diagonal[row + col] = 1;
      }
    }
  }
};
