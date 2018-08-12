class Solution {
public:
  bool isAdditiveNumber(string num) {
    for (int i = 1; i < num.size(); ++i) {
      for (int j = i + 1; j < num.size(); ++j) {
        string s1 = num.substr(0, i);
        string s2 = num.substr(i, j - i);
        auto n1 = atoll(s1.c_str());
        auto n2 = atoll(s2.c_str());
        if ((s1.size() > 1 && s1[0] == '0') ||
            (s2.size() > 1 && s2[0] == '0')) {
          continue;
        }
        auto n = n1 + n2;
        string next = to_string(n);
        string now = s1 + s2 + next;
        while (now.size() < num.size()) {
          n1 = n2;
          n2 = n;
          n = n1 + n2;
          next = to_string(n);
          now += next;
        }
        if (now == num) {
          return true;
        }
      }
    }
    return false;
  }
};
