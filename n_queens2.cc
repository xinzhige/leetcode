class Solution {
public:
  // A[i] represents at which column for queen on row i
  bool is_valid(int A[], int row) {
    // we only need to consider rows before row because 
    // rows after have not been set
    for (int i = 0; i < row; ++i) {
      if ((A[row] == A[i]) || (abs(A[row] - A[i]) == row - i)) {
	      return false;
      }
    }
    return true;
  }
  void n_queens(int A[], int curr, int n, int& result) {
    if (curr == n) {
      ++result;
      return;
    } else {
      for (int i = 0; i < n; ++i) {
	      A[curr] = i;
	      if (is_valid(A, curr)){
	        n_queens(A, curr + 1, n, result);
	      }
      }
    }
  }
  int totalNQueens(int n) {
    int result = 0;
    int A[n];
    n_queens(A, 0, n, result);
    return result;
  }
};
