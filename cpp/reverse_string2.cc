class Solution {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int start = 0; start < n; start += 2 * k) {
      int i = start;
      int j = min(start + k - 1, n - 1);
      reverse(s.begin() + i, s.begin() + j + 1);
    }
    return s;
  }
};
