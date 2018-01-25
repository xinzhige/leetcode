class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0];
    int right = matrix.back().back();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int count = searchLessEqual(matrix, mid);
      if (count < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
  int searchLessEqual(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    // Search from the left-bottom of the matrix
    int i = n - 1;
    int j = 0;
    int result = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= target) {
        result += i + 1;
        ++j;
      } else {
        --i;
      }
    }
    return result;
  }
};
