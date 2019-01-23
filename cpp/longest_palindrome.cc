class Solution {
public:
  int longestPalindrome(string s) {
    int result = 0;
    unordered_map<char, int> freq;
    for (const auto &c : s) {
      freq[c] += 1;
    }
    bool odd = false;
    for (const auto &f : freq) {
      if (f.second % 2 == 0) {
        result += f.second;
      } else {
        if (!odd) {
          odd = true;
        }
        result += f.second - 1;
      }
    }
    return odd ? result + 1 : result;
  }
};
