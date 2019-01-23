class Solution {
public:
  bool isPalindrome(string s) {
    int low = 0;
    int high = s.size() - 1;
    while (low < high) {
      if (!isalnum(s[low])) {
        low += 1;
      } else if (!isalnum(s[high])) {
        high -= 1;
      } else {
        if (tolower(s[low]) == tolower(s[high])) {
          low += 1;
          high -= 1;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
