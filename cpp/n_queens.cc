// Bitmask
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> nQueens(n, string(n, '.'));
    vector<int> flag_col(n, 1);
    vector<int> flag_45(2 * n - 1, 1);
    vector<int> flag_135(2 * n - 1, 1);
    solveNQueens(n, 0, nQueens, flag_col, flag_45, flag_135, result);
    return result;
  }
private:
  void solveNQueens(const int &n, int row, vector<string> &nQueens,
                    vector<int> &flag_col, vector<int> &flag_45,
                    vector<int> &flag_135, vector<vector<string>> &result) {
    if (row == n) {
      result.push_back(nQueens);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (flag_col[col] == 1 && flag_45[row + col] == 1 &&
          flag_135[n - 1 + col - row] == 1) {
        flag_col[col] = 0;
        flag_45[row + col] = 0;
        flag_135[n - 1 + col - row] = 0;
        nQueens[row][col] = 'Q';
        solveNQueens(n, row + 1, nQueens, flag_col, flag_45, flag_135, result);
        nQueens[row][col] = '.';
        flag_col[col] = 1;
        flag_45[row + col] = 1;
        flag_135[n - 1 + col - row] = 1;
      }
    }
  }
};
