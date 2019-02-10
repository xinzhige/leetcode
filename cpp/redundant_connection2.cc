class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);
    vector<int> first;
    vector<int> second;
    for (auto &e : edges) {
      if (parent[e[1]] == 0) {
        parent[e[1]] = e[0];
      } else {
        first = {parent[e[1]], e[1]};
        second = e;
        e[1] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    for (const auto &e : edges) {
      if (e[1] != 0) {
        int p = find(parent, e[0]);
        if (p == e[1]) {
          if (first.empty()) {
            // has cycle without two parents
            return e;
          } else {
            // has cycle with two parents
            return first;
          }
        }
        parent[e[1]] = p;
      }
    }
    // no cycle but with two parents
    return second;
  }
  int find(vector<int>& parent, int x) {
    for (; x != parent[x]; x = parent[x]) {
      parent[x] = parent[parent[x]];
    }
    return x;
  }
};
