// method 1 brute force, scan from the first char of the string but can be modified as the solution to the longest or shortest length word in the string
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (strlen(s) == 0) {
            return 0;
        }
        int i = 0;
        int curr_len = 0;
        int result = 0;
        while (s[i] != '\0') {
            curr_len = 0;
            while (s[i] != ' ' && s[i] != '\0') {
                ++curr_len;
                ++i;
            }
            if (curr_len != 0) {
                result = curr_len;
            }
            if (s[i] == ' ') {
                ++i;
            }
        }
        return result;
    }
};

// method 2 start from the end of the string, more concise 
class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int s_len = strlen(s);
    if (s_len == 0) {
      return 0;
    }
    int result = 0;
    for (int i = s_len-1; i >= 0; --i) {
      if (s[i] != ' ') {
	result++;
      } else if (result > 0) {
	return result;
      } 
    }
    return result;
  }
};
