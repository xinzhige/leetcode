// The first integer of each row is greater than the last integer of the previous row. time: O(lgn)
class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.empty()) {
      return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int begin = 0;
    int end = m * n - 1;
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      int i = mid / n;
      int j = mid % n;
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};
