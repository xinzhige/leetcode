// Idea: binary indexed tree, time: O(log(m)*log(n))
class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    if (matrix.empty()) {
      return;
    }
    m = matrix.size();
    n = matrix[0].size();
    tree = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    nums = vector<vector<int>>(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        update(i, j, matrix[i][j]);
      }
    }
  }

  void update(int row, int col, int val) {
    int delta = val - nums[row][col];
    nums[row][col] = val;
    for (int i = row + 1; i <= m; i += i & (-i)) {
      for (int j = col + 1; j <= n; j += j & (-j)) {
        tree[i][j] += delta;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum(row2 + 1, col2 + 1) + sum(row1, col1) -
      sum(row1, col2 + 1) - sum(row2 + 1, col1);
  }
  int sum(int row, int col) {
    int result = 0;
    for (int i = row; i > 0; i -= i & (-i)) {
      for (int j = col; j > 0; j -= j & (-j)) {
        result += tree[i][j];
      }
    }
    return result;
  }

private:
  vector<vector<int>> tree;
  vector<vector<int>> nums;
  int m = 0;
  int n = 0;
};
