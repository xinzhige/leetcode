class Solution {
public:
  bool checkRecord(string s) {
    int numA = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'A') {
        numA += 1;
        if (numA > 1) {
          return false;
        }
      }
      if (i <= s.size() - 3 && s.substr(i, 3) == "LLL") {
        return false;
      }
    }
    return numA < 2;
  }
};
