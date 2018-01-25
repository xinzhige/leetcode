class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> roots(n);
    for (int i = 0; i < n; ++i) {
      roots[i] = i;
    }
    int x = 0;
    int y = 0;
    int result = n;
    for (const auto &e : edges) {
      x = find(roots, e.first);
      y = find(roots, e.second);
      if (x != y) {
        --result;
        roots[y] = x;
      }
    }
    return result;
  }
  int find(vector<int> &roots, int i) {
    for (; roots[i] != i; i = roots[i]);
    return i;
  }
};
