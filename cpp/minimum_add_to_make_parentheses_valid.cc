// Idea: left records the number of ( we need to add and right records
// the current opened parentheses.
right records the current opened parentheses.
class Solution {
public:
  int minAddToMakeValid(string S) {
    int left = 0;
    int right = 0;
    for (const char &c : S) {
      if (right == 0 && c == ')') {
        left += 1;
      } else {
        right += (c == '(' ? 1 : -1);
      }
    }
    return left + right;
  }
};
