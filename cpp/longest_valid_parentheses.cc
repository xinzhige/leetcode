class Solution {
public:
  int longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int maxLength = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        left += 1;
      } else {
        right += 1;
      }
      if (left == right) {
        maxLength = max(maxLength, 2*right);
      } else if (left <= right) {
        left = 0;
        right = 0;
      }
    }
    left = 0;
    right = 0;
    for (int i = s.size()- 1; i >= 0; --i) {
      if (s[i] == ')') {
        right += 1;
      } else {
        left += 1;
      }
      if (left == right) {
        maxLength = max(maxLength, 2*left);
      } else if (left >= right) {
        left = 0;
        right = 0;
      }
    }
    return maxLength;
  }
};
