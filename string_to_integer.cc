class Solution {
public:
  int atoi(const char *str) {
    int result = 0;
    int sign = 1;
    while(*str == ' ') {
      str++;
    }
    if (*str == '+') {
        ++str;
    }
    if (*str == '-') {
	  sign = -1;
      ++str;
    }
    while (*str != '\0') {
      if (*str < '0' || *str > '9') {
        break;
      }
      int digit = *str - '0';
      if (result > INT_MAX / 10  || 
        (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
	    return sign == 1 ? INT_MAX : INT_MIN;
      }
      result = 10*result + digit;
      ++str;
    }
    return sign*result;
  }
};
