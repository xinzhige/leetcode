// Time: O(n!), space: O(n^2)
class Solution {
public:
  int numberOfPatterns(int m, int n) {
    int result = 0;
    vector<int> visited(9, 0);
    vector<vector<int>> jumps(10, vector<int>(10, 0));
    jumps[1][3] = jumps[3][1] = 2;
    jumps[4][6] = jumps[6][4] = 5;
    jumps[7][9] = jumps[9][7] = 8;
    jumps[1][7] = jumps[7][1] = 4;
    jumps[2][8] = jumps[8][2] = 5;
    jumps[3][9] = jumps[9][3] = 6;
    jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
    result += backtrack(1, 1, m, n, 0, visited, jumps) * 4;
    result += backtrack(2, 1, m, n, 0, visited, jumps) * 4;
    result += backtrack(5, 1, m, n, 0, visited, jumps);
    return result;
  }
  int backtrack(int num, int len, int m, int n, int result,
                vector<int> &visited, vector<vector<int>> &jumps) {
    if (len >= m) {
      result += 1;
    }
    len += 1;
    if (len > n) {
      return result;
    }
    visited[num] = true;
    for (int next = 1; next <= 9; ++next) {
      int jump = jumps[num][next];
      if (visited[next] == 0 && (jump == 0 || visited[jump] == 1)) {
        result = backtrack(next, len, m, n, result, visited, jumps);
      }
    }
    visited[num] = 0;
    return result;
  }
};


// Time: O(n!), space: O(1)
class Solution {
public:
  int numberOfPatterns(int m, int n) {
    return count(m, n, 0, 1, 1);
  }
  int count(int m, int n, int used, int i1, int j1) {
    int result = (m <= 0 ? 1 : 0);
    if (n == 0) {
      return 1;
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int I = i1 + i;
        int J = j1 + j;
        int used2 = (used | (1 << (i * 3 + j)));
        if (used2 > used &&
            (I % 2 || J % 2 || used2 & (1 << (I / 2 * 3 + J / 2)))) {
          result += count(m - 1, n - 1, used2, i, j);
        }
      }
    }
    return result;
  }
};
