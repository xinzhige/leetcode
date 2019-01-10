// Backtracking
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> nQueens(n, string(n, '.'));
    solveNQueens(n, 0, nQueens, result);
    return result;
  }
private:
  void solveNQueens(const int &n, int row, vector<string> &nQueens,
                    vector<vector<string>> &result) {
    if (row == n) {
      result.push_back(nQueens);
      return;
    }
    for (int col = 0; col < n; ++col)
      if (isValid(nQueens, row, col, n)) {
        nQueens[row][col] = 'Q';
        solveNQueens(n, row + 1, nQueens, result);
        nQueens[row][col] = '.';
      }
  }
  bool isValid(vector<string> &nQueens, int row, int col, const int &n) {
    for (int i = 0; i < row; ++i) {
      if (nQueens[i][col] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (nQueens[i][j] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (nQueens[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
