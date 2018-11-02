class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    int i = 0;
    int j = 0;
    // asterisk points to the last position of '*' in p and
    // match points to the corresponding position in s.
    int asterisk = -1;
    int match = 0;
    while (i < m) {
      if (j < n && (s[i] == p[j] || p[j] == '?')) {
        ++i;
        ++j;
      } else if (j < n && p[j] == '*') {
        match = i;
        asterisk = j;
        ++j;
      } else if (asterisk >= 0) {
        ++match;
        i = match;
        j = asterisk + 1;
      } else {
        return false;
      }
    }
    while (j < n && p[j] == '*') {
      ++j;
    }
    return j == n;
  }
};
