class Solution {
public:
  string shortestPalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + "#" + r;
    vector<int> next(t.size(), 0);
    for (int j = 0, i = 1; i < t.size(); i++) {
      while (j > 0 && t[i] != t[j]) {
        j = next[j - 1];
      }
      if (t[i] == t[j]) {
        j += 1;
      }
      next[i] = j;
    }
    return r.substr(0, s.size() - next.back()) + s;
  }
};
