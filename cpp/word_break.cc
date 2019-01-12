class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<int> result(n + 1, 0);
    unordered_set<string> dict;
    for (const auto & word : wordDict) {
      dict.insert(word);
    }
    result[0] = 1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (result[j] == 1 && dict.count(s.substr(j, i - j)) > 0) {
          result[i] = 1;
          break;
        }
      }
    }
    return result[n] == 1;
  }
};
