class Solution {
public:
  int longestSubstring(string s, int k) {
    int result = 0;
    // h is the number of unique characters
    for (int h = 1; h <= 26; ++h) {
      vector<int> counts(26, 0);
      int i = 0;
      int j = 0;
      int unique = 0;
      int noLessThanK = 0;
      int index = 0;
      while (j < s.size()) {
        if (unique <= h) {
          index = s[j] - 'a';
          if (counts[index] == 0) {
            unique += 1;
          }
          counts[index] += 1;
          if (counts[index] == k) {
            noLessThanK += 1;
          }
          ++j;
        } else {
          index = s[i] - 'a';
          if (counts[index] == k) {
            noLessThanK -= 1;
          }
          counts[index] -= 1;
          if (counts[index] == 0) {
            unique -= 1;
          }
          ++i;
        }
        if (unique == noLessThanK) {
          result = max(result, j - i);
        }
      }
    }
    return result;
  }
};
