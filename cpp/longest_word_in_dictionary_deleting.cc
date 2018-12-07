// Idea: go through each word in dictionary and compare it to s, if
// s contains all the characters and meets the following two conditions, then
// replace the result:
// 1. current word size is larger;
// 2. current word size is equal to result but smaller lexicographical order.
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
      if (i == word.size()) {
        if (word.size() > result.size() ||
            (word.size() == result.size() && word < result)) {
          result = word;
        }
      }
    }
    return result;
  }
};
