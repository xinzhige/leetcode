class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; ; ++i) {
      for (int j = 0; ; ++j) {
        if (j == needle.size()) {
          return i;
        }
        if (i + j == haystack.size()) {
          return -1;
        }
        if (needle[j] != haystack[i + j]) {
          break;
        }
      }
    }
  }
};

// Sunday algorithm
class Solution {
public:
  int strStr(string haystack, string needle) {
    unordered_map<char, int> index;
    for (int i = needle.size() - 1; i >= 0; --i) {
      if (index.count(needle[i]) == 0) {
        index[needle[i]] = i;
      }
    }
    if (needle.empty()) {
      return 0;
    }
    int m = haystack.size();
    int n = needle.size();
    if (m < n) {
      return -1;
    }
    int i = 0;
    int j = 0;
    while (i <= m - n) {
      j = 0;
      for (; j < n && haystack[i+j] == needle[j]; ++j);
      if (j == n) {
        return i;
      }
      i += n;
      if (i < m) {
        int badCharIndex = 0;
        if (index.count(haystack[i]) == 0) {
          badCharIndex = -1;
        } else {
          badCharIndex = index[haystack[i]];
        }
        i -= badCharIndex;
      }
    }
    return -1;
  }
};
