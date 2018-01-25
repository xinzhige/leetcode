class Solution {
public:
  bool isNumber(string s) {
    bool num = false;
    bool numAfterE = true;
    bool dot = false;
    bool exp = false;
    bool sign = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if (i < s.size() - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) {
          return false;
        }
      } else if (s[i] == '+' || s[i] == '-') {
        if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') {
          return false;
        }
        sign = true;
      } else if (isdigit(s[i])) {
        num = true;
        numAfterE = true;
      } else if (s[i] == '.') {
        if (dot || exp) {
          return false;
        }
        dot = true;
      } else if (s[i] == 'e') {
        if (exp || !num) {
          return false;
        }
        exp = true;
        numAfterE = false;
      } else {
        return false;
      }
    }
    return num && numAfterE;
  }
};
