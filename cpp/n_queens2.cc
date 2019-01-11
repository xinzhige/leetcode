// Backtracking + Bitmask
class Solution {
public:
  int totalNQueens(int n) {
    int result = 0;
    set<int> cols;
    set<int> diagonal;
    set<int> anti_diagonal;
    totalNQueensHelper(n, 0, cols, diagonal, anti_diagonal, result);
    return result;
  }
private:
  void totalNQueensHelper(const int& n, int row, set<int>& cols,
                          set<int>& diagonal, set<int>& anti_diagonal,
                          int& result) {
    if (row == n) {
      result += 1;
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (cols.count(col) == 0 && diagonal.count(row - col) == 0 &&
          anti_diagonal.count(row + col) == 0) {
        cols.insert(col);
        diagonal.insert(row - col);
        anti_diagonal.insert(row + col);
        totalNQueensHelper(n, row + 1, cols, diagonal, anti_diagonal, result);
        cols.erase(col);
        diagonal.erase(row - col);
        anti_diagonal.erase(row + col);
      }
    }
  }
};
