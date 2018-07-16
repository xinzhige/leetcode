class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> result;
    int i = 0;
    int n = S.size();
    for (int j = 0; j < n; ++j) {
      if (j == n - 1 || S[j] != S[j+1]) {
        if (j - i >= 2) {
          result.push_back({i, j});
        }
        i = j + 1;
      }
    }
    return result;
  }
};
