class Solution {
public:
  int countSubstrings(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      extendPalindrome(s, i, i, count);
      extendPalindrome(s, i, i + 1, count);
    }
    return count;
  }
  void extendPalindrome(string s, int left, int right, int& count) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      ++count;
      --left;
      ++right;
    }
  }
};

// DP
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    int result = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
        if (dp[i][j]) {
          ++result;
        }
      }
    }
    return result;
  }
};
