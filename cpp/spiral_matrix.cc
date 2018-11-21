class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if (matrix.empty()) {
      return result;
    }
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    for (; left <= right && top <= bottom; ++left, --right, ++top, --bottom) {
      for (int j = left; j <= right; ++j) {
        result.emplace_back(matrix[top][j]);
      }
      for (int i = top + 1; i < bottom; ++i) {
        result.emplace_back(matrix[i][right]);
      }
      for (int j = right; top < bottom && j >= left; --j) {
        result.emplace_back(matrix[bottom][j]);
      }
      for (int i = bottom - 1; left < right && i > top; --i) {
        result.emplace_back(matrix[i][left]);
      }
    }
    return result;
  }
};
