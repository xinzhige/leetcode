class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
      vector<int> result;
      int count = 0;
      vector<int> roots(m * n, -1);
      vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
      for (const auto &pos : positions) {
        int id = n * pos.first + pos.second;
        if (roots[id] == -1) {
          roots[id] = id;
          count += 1;
        }
        for (const auto &dir : dirs) {
          int x = pos.first + dir[0];
          int y = pos.second + dir[1];
          int curr_id = n * x + y;
          if (x >= 0 && x < m && y >= 0 && y < n && roots[curr_id] != -1) {
            int p = findRoot(roots, curr_id);
            int q = findRoot(roots, id);
            if (p != q) {
              roots[p] = q;
              count -= 1;
            }
          }
        }
        result.push_back(count);
      }
      return result;
    }
  int findRoot(vector<int>& roots, int id) {
    for (; id != roots[id]; id = roots[id]) {
      roots[id] = roots[roots[id]];
    }
    return id;
  }
};
