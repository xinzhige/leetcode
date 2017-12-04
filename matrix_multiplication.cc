class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();
    int l = A[0].size();
    int n = B[0].size();
    vector<vector<int>> C(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < l; ++k) {
          if (A[i][k] != 0 && B[k][j] != 0) {
            C[i][j] += A[i][k] * B[k][j];
          }
        }
      }
    }
    return C;
  }
};
