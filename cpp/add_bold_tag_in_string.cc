class Solution {
public:
  string addBoldTag(string s, vector<string>& dict) {
    int n = s.size();
    unordered_set<int> bold;
    for (const auto &w : dict) {
      int len = w.size();
      for (int i = 0; i <= n - len; ++i) {
        if (w[0] == s[i] && s.substr(i, len) == w) {
          for (int j = i; j < i + len; ++j) {
            bold.insert(j);
          }
        }
      }
    }
    string result("");
    for (int i = 0; i < n; ++i) {
      if (bold.count(i) > 0 && bold.count(i-1) == 0) {
        result += "<b>";
      }
      result += s[i];
      if (bold.count(i) > 0 && bold.count(i+1) == 0) {
        result += "</b>";
      }
    }
    return result;
  }
};
