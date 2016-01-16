class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
      return;
    }
    int cols = matrix[0].size();
    bool first_row_has0(false);
    bool first_col_has0(false);
    int i,j;
    for (i = 0; i < rows; ++i) {
      if (matrix[i][0] == 0) {
	first_col_has0 = true;
	break;
      }
    }
    for (j = 0; j < cols; ++j) {
      if (matrix[0][j] == 0) {
	first_row_has0 = true;
	break;
      }
    }
    for (i = 1; i < rows; ++i) {
      for (j = 1; j < cols; ++j) {
	if (matrix[i][j] == 0) {
	  if (matrix[0][j] != 0) {
	    matrix[0][j] = 0;
	  }
	  if (matrix[i][0] != 0) {
	    matrix[i][0] = 0;
	  }
	}
      }
    }
    for (i = 1; i < rows; i++) {
      for (j = 1; j < cols; j++) {
	if (matrix[i][0] == 0 || matrix[0][j] == 0) {
	  matrix[i][j] = 0;
	}
      }
    }
    if (first_col_has0) {
      for (i = 0; i < rows; i++) {
	matrix[i][0] = 0;
      }
    }
    if (first_row_has0) {
      for (j = 0; j < cols; j++) {
	matrix[0][j] = 0;
      }
    }
  }
};
