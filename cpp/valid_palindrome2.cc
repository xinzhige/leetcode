class Solution {
public:
  bool validPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - 1 - i]) {
        int j = n - 1 - i;
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
      }
    }
    return true;
  }
  bool isPalindrome(string s, int i, int j) {
    for (; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};
