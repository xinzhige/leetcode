// Time: O(R^2 * C), space: O(1)
class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int result = 0;
    int m = grid.size();
    if (m == 0) {
      return 0;
    }
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        int count = 0;
        for (int k = 0; k < n; ++k) {
          if (grid[i][k] == 1 && grid[j][k] == 1) {
            count += 1;
          }
        }
        result += (count * (count - 1)) / 2;
      }
    }
    return result;
  }
};


// Time: O(N^1.5), space: O(N + R + C^2)
class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int result = 0;
    int m = grid.size();
    if (m == 0) {
      return 0;
    }
    int n = grid[0].size();
    vector<vector<int>> rows;
    int N = 0;
    for (int r = 0; r < m; ++r) {
      vector<int> curr;
      rows.push_back(curr);
      for (int c = 0; c < n; ++c) {
        if (grid[r][c] == 1) {
          rows[r].push_back(c);
          ++N;
        }
      }
    }
    int sqrtN = (int)sqrt(N);
    unordered_map<int, int> count;
    for (int r = 0; r < m; ++r) {
      if (rows[r].size() >= sqrtN) {
        set<int> target{rows[r].begin(), rows[r].end()};
        for (int r2 = 0; r2 < m; ++r2) {
          if (r2 <= r && rows[r2].size() >= sqrtN) {
            continue;
          }
          int found = 0;
          for (int c2 : rows[r2]) {
            if (target.count(c2)) {
              ++found;
            }
          }
          result += (found * (found - 1)) / 2;
        }
      } else {
        for (int i1 = 0; i1 < rows[r].size(); ++i1) {
          int c1 = rows[r][i1];
          for (int i2 = i1 + 1; i2 < rows[r].size(); ++i2) {
            int c2 = rows[r][i2];
            int tmp = 200*c1 + c2;
            int ct = count.count(tmp) ? count[tmp] : 0;
            result += ct;
            count[tmp] =  ct + 1;
          }
        }
      }
    }
    return result;
  }
};
