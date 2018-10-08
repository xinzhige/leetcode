class Solution {
public:
  string removeKdigits(string num, int k) {
    string result = "";
    int keep = num.size() - k;
    for (const auto &c : num) {
      while (k > 0 && !result.empty() && result.back() > c) {
        result.pop_back();
        --k;
      }
      result.push_back(c);
    }
    result.resize(keep);
    for (; !result.empty() && result[0] == '0'; result.erase(result.begin()));
    return result.empty() ? "0" : result;
  }
};
