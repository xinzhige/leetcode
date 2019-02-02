class Solution {
public:
  string countAndSay(int n) {
    if (n < 1) {
      return "";
    }
    string result = "1";
    n -= 1;
    for (; n > 0; --n) {
      result.push_back('#');
      string t = "";
      int count = 1;
      for (int i = 1; i < result.size(); ++i) {
        if (result[i] == result[i - 1]) {
          ++count;
        } else {
          t += to_string(count) + result[i - 1];
          count = 1;
        }
      }
      result = t;
    }
    return result;
  }
};
