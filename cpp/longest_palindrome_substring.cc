class Solution {
public:
  string expandAroundCenter(string s, int left, int right) {
    int l = left;
    int r = right;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }
    int n = s.length();
    // a single char itself is a palindrome
    string longest = s.substr(0, 1);
    for (int i = 0; i < n - 1; i++) {
      string p1 = expandAroundCenter(s, i, i);
      // center is a char
      if (p1.length() > longest.length()) {
        longest = p1;
      }
      string p2 = expandAroundCenter(s, i, i + 1);
      // center is in between two neighbor chars
      if (p2.length() > longest.length()) {
        longest = p2;
      }
    }
    return longest;
  }
};
