// Idea, use two variables, low is how many '(' if current '*' is taken as
// ')' and high is how many '(' if current '*' is taken as '('.
class Solution {
public:
  bool checkValidString(string s) {
    int low = 0;
    int high = 0;
    for (const char &c : s) {
      if (c == '(') {
        ++low;
        ++high;
      } else if (c == ')') {
        if (low > 0) {
          --low;
        }
        --high;
      } else {
        if (low > 0) {
          --low;
        }
        ++high;
      }
      if (high < 0) {
        return false;
      }
    }
    return low == 0;
  }
};
