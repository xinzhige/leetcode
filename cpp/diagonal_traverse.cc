// Coordinate (i, j) on this diagonal complies to: i+j=level.
// For example, [2, 0], [1, 1], [0, 2], 2+0=1+1=0+2=2.
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int k = 0;
    vector<int> result(m * n, 0);
    for (int i = 0; i < m + n - 1; ++i) {
      int low = max(0, i - n + 1);
      int high = min(i, m - 1);
      if ((i % 2) == 0) {
        for (int j = high; j >= low; --j) {
          result[k] = matrix[j][i - j];
            ++k;
        }
      } else {
        for (int j = low; j <= high; ++j) {
          result[k] = matrix[j][i - j];
          ++k;
        }
      }
    }
    return result;
  }
};
