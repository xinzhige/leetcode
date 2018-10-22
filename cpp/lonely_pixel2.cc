class Solution {
public:
  int findBlackPixel(vector<vector<char>>& picture, int N) {
    if (picture.empty() || picture[0].empty()) {
      return 0;
    }
    int m = picture.size();
    int n = picture[0].size();
    int result = 0;
    vector<int> cols(n, 0);
    unordered_map<string, int> rows;
    for (int i = 0; i < m; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          cols[j] += 1;
          count += 1;
        }
      }
      if (count == N) {
        rows[string(picture[i].begin(), picture[i].end())] += 1;
      }
    }
    for (const auto &r : rows) {
      if (r.second == N) {
        for (int j = 0; j < n; ++j) {
          if (r.first[j] == 'B' && cols[j] == N) {
            result += N;
          }
        }
      }
    }
    return result;
  }
};
