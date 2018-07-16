class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int result = 0;
    for (int i = 0; i < m - 2; ++i)
      for (int j = 0; j < n - 2; ++j) {
        if (grid[i+1][j+1] == 5) {
          vector<int> tmp(16, 0);
          for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
              tmp[r+3*c] = grid[i+r][j+c];
            }
          }
          if (isMagic(tmp)) {
            result += 1;
          }
        }
      }
    return result;
  }
  bool isMagic(vector<int>& S) {
    vector<int> count(16, 0);
    for (auto &v: S) {
      count[v] += 1;
    }
    for (int i = 1; i <= 9; ++i) {
      if (count[i] != 1) {
        return false;
      }
    }
    return (S[0] + S[1] + S[2] == 15 &&
            S[3] + S[4] + S[5] == 15 &&
            S[6] + S[7] + S[8] == 15 &&
            S[0] + S[3] + S[6] == 15 &&
            S[1] + S[4] + S[7] == 15 &&
            S[2] + S[5] + S[8] == 15 &&
            S[0] + S[4] + S[8] == 15 &&
            S[2] + S[4] + S[6] == 15);
  }
};
