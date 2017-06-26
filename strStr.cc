class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int m = haystack.size();
        int n = needle.size();
        if (m < n) {
            return -1;
        }
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

// Sunday algorithm
class Solution {
public:
  int strStr(string haystack, string needle) {
    unordered_map<char, int> mymap;
    for (int i = needle.size() - 1; i >= 0; --i) {
      if (mymap.find(needle[i]) == mymap.end()) {
	mymap[needle[i]] = i;
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
    while (i <= m -n) {
      j = 0;
      for (; j < n && haystack[i+j] == needle[j]; ++j);
      if (j == n) {
	return i;
      }
      i += n;
      if (i < m) {
	int badCharIndex = 0;
	if (mymap.find(haystack[i]) == mymap.end()) {
	  badCharIndex = -1;
	} else {
	  badCharIndex = mymap[haystack[i]];
	}
	i -= badCharIndex;
      }
    }
    return -1;
  }
};
