// time: O(m*n), space: O(1)
class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    const char* star = nullptr;
    const char* ss = s; 
    while (*s != '\0') {
      if ((*p == '?') || (*p == *s)) {
    	++s; 
    	++p;
    	continue;
      } else if (*p == '*') { 
    	star = p; 
    	++p;
    	ss = s;
    	continue;
      } else if (star != nullptr) { 
    	p = star + 1; 
    	++ss;
    	s = ss;
    	continue;
      } else {
        return false;
      }
    }
    while (*p == '*') ++p;
    return *p == '\0';
  }
};
