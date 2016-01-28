class Solution {
public:
  string expandAroundCenter(string s, int left, int right) {
    int l = left, r = right;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }
  string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) {
      return "";
    }
    string longest = s.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n - 1; i++) {
      string p1 = expandAroundCenter(s, i, i);
      if (p1.length() > longest.length()) { // center is a char
	longest = p1;
      }
      
      string p2 = expandAroundCenter(s, i, i + 1);
      if (p2.length() > longest.length()) { // center is in between two neighbor chars
	longest = p2;
      }
    }
    return longest;
  }
};
