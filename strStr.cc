// brute force
class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    for (;;++haystack) {
      char* h = haystack;
      for (char* n = needle;; ++n, ++h) {
	if (*n == '\0') {
	  return haystack;
	}
	if (*h != *n) {
	  break;
	}
      }
      if (*h == '\0') {
	return nullptr;
      }
    }
  }
};

// use a pointer points to the current end to prevent the end of needle falls behind that of the haystack so the outer loop just takes n-m+1
class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    if (!(*needle)) {
      return haystack;
    }
    char *p1 = haystack;
    char *p2 = needle;
    char *pEnd = haystack;
    while (*(++p2)) {
      ++pEnd;
    }
    while (*pEnd) {
      char *pBegin = p1;
      p2 = needle;
      while (*p1 && *p2 && *p1 == *p2) {
	++p1;
	++p2;
      }
      if (!(*p2)) {
	return pBegin;
      }
      p1 = pBegin + 1;
      ++pEnd;
    }
    return nullptr;
  }
};
