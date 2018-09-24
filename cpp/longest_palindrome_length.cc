class Solution {
public:
  int longestPalindrome(string s) {
    int result = 0;
    unordered_map<char, int> count;
    for (const auto &c : s) {
      count[c] += 1;
    }
    int numOdd = 0;
    for (auto it = count.begin(); it != count.end(); ++it) {
      if ((it->second % 2) == 0) {
        result += it->second;
      } else {
        numOdd += 1;
        result += it->second - 1;
      }
    }
    if (numOdd == 0) {
      return result;
    } else {
      return result + 1;
    }
  }
};
