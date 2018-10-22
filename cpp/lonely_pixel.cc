// Time: O(mn), space: O(m+n)
class Solution {
public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    int m = picture.size();
    int n = picture[0].size();
    int result = 0;
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          row[i] += 1;
          col[j] += 1;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      if (row[i] == 1) {
        for (int j = 0; j < n; ++j) {
          if (col[j] == 1 && picture[i][j] == 'B') {
            result += 1;
            break;
          }
        }
      }
    }
    return result;
  }
};


// Space: O(1)
class Solution {
public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    int m = picture.size();
    int n = picture[0].size();
    int rows = 0;
    int cols = 0;
    for (int i = 0; i < m; ++i) {
      int r = 0;
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++r;
        }
      }
      if (r == 1) {
        rows += 1;
      }
    }
    for (int j = 0; j < n; ++j) {
      int c = 0;
      for (int i = 0; i < m; ++i) {
        if (picture[i][j] == 'B') {
          ++c;
        }
      }
      if (c == 1) {
        cols += 1;
      }
    }
    return min(rows, cols);
  }
};
