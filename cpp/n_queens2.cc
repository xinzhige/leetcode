class Solution {
public:
  bool isValid(vector<int>& A, int row) {
    for (int i = 0; i < row; ++i) {
      if ((A[row] == A[i]) || 
	  (abs(A[row] - A[i]) == row - i)) {
        return false;
      }
    }
    return true;
  }
  void nQueens(vector<int> A, int row, int n, int& result) {
    if (row == n) {
      result += 1;
      return;
    } else {
      for (int col = 0; col < n; col++) {
        A[row] = col;
	if (isValid(A, row)){
	  nQueens(A, row + 1, n, result);
	}
      }
    }
  }
  int totalNQueens(int n) {
    int result = 0;
    vector<int> A(n, 0);
    nQueens(A, 0, n, result);
    return result;
  }
};
