class Solution {
public:
  bool isAlphanumeric(char c) {
    if(c >= '0' && c <= '9' || c >= 'a' && c <= 'z') {
      return true;
    }
    return false;
  }
  char lowerCase(char c) {
    if(c >= 'A' && c <= 'Z') {
      c += 32;
    }
    return c;
  }
  bool isPalindrome(string s) {
    int i = 0, j = s.size()-1;
    while(i < j) {
      char left = lowerCase(s[i]);
      char right = lowerCase(s[j]);
      if (!isAlphanumeric(left)) {
	i++;
      }
      else if (!isAlphanumeric(right)) {
	j--;
      }
      else {
	if (left == right) {
	  i++;
	  j--;
	} else {
	  return false;
	}
      }
    }
    return true;
  }
};
