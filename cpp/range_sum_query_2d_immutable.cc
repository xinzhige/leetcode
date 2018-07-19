class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    int m = matrix.size();
    if (m == 0) {
      return;
    }
    int n = matrix[0].size();
    mymatrix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        mymatrix[r+1][c+1] += mymatrix[r+1][c] + mymatrix[r][c+1] -
          mymatrix[r][c] + matrix[r][c];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return mymatrix[row2+1][col2+1] + mymatrix[row1][col1] -
      mymatrix[row1][col2+1] - mymatrix[row2+1][col1];
  }

private:
  vector<vector<int>> mymatrix;
};
