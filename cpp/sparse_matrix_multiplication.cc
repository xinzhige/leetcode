class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.empty() || A[0].empty() || B.empty() || B[0].empty() ||
        A[0].size() != B.size()) {
      return {};
    }
    int m = A.size();
    int l = B.size();
    int n = B[0].size();
    vector<vector<int>> C(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < l; ++k) {
        if (A[i][k] != 0) {
          for (int j = 0; j < n; ++j) {
            if (B[k][j] != 0) {
              C[i][j] += A[i][k] * B[k][j];
            }
          }
        }
      }
    }
    return C;
  }
};
