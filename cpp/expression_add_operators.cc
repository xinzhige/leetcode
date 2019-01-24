// Backtracking
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> result;
    backtrack(num, target, 0, 0, "", result);
    return result;
  }
  void backtrack(const string &num, int target, long long diff,
                 long long curNum, const string &out,
                 vector<string> &result) {
    if (num.size() == 0 && curNum == target) {
      result.push_back(out);
    }
    for (int i = 1; i <= num.size(); ++i) {
      string cur = num.substr(0, i);
      // Skip the number like "01"
      if (cur.size() <= 1 || cur[0] != '0') {
        string next = num.substr(i);
        if (out.size() > 0) {
          backtrack(next, target, stoll(cur), curNum + stoll(cur),
                    out + "+" + cur, result);
          backtrack(next, target, -stoll(cur), curNum - stoll(cur),
                    out + "-" + cur, result);
          // For example, 1: 2+3*2, curNum=5, diff=3, cur="2",
          // (5-3)+3*2=8=2+3*2
          // 2: 2*3*2, curNum=6, diff=6, cur="2"
          // 6-6+6*2=12=2*3*2
          backtrack(next, target, diff * stoll(cur),
                    (curNum - diff) + diff * stoll(cur), out + "*" + cur,
                    result);
        } else {
          backtrack(next, target, stoll(cur), stoll(cur), cur, result);
        }
      }
    }
  }
};
