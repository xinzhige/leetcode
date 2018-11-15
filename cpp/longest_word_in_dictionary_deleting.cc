class Solution {
public:
  string findLongestWord(string s, vector<string>& d) {
    string result("");
    for (const auto &word : d) {
      int i = 0;
      for (const auto &c : s) {
        if (i < word.size() && c == word[i]) {
          ++i;
        }
      }
      if (i == word.size() && word.size() >= result.size()) {
        if (word.size() > result.size() || word < result) {
          result = word;
        }
      }
    }
    return result;
  }
};
