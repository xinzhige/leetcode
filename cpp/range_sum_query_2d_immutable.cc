class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] -
          sum[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum[row2+1][col2+1] + sum[row1][col1] -
      sum[row1][col2+1] - sum[row2+1][col1];
  }

private:
  vector<vector<int>> sum;
};
