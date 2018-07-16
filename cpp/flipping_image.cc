class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); ++i) {
      reverse(A[i].begin(), A[i].end());
    }
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A.size(); ++j) {
        A[i][j] = 1 - A[i][j];
      }
    }
    return A;
  }
};


// One loop
// In each row, the ith value from the left is equal to
// the inverse of the ith value from the right.
class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int m = A[0].size();
    for (auto &row : A) {
      for (int i = 0; i < (m + 1) / 2; ++i) {
        int tmp = row[i] ^ 1;
        row[i] = row[m - 1 - i] ^ 1;
        row[m - 1 - i] = tmp;
      }
    }
    return A;
  }
};
