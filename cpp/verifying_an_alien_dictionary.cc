// Note: once a corresponding character is not equal, comparison can be made.
class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> translation;
    for (int i = 0;i < order.size(); ++i) {
      translation[order[i]] = i;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
      string word1 = words[i];
      string word2 = words[i + 1];
      if (alienStringCompare(word1, word2, translation) > 0) {
        return false;
      }
    }
    return true;
  }
  int alienStringCompare(const string &word1, const string &word2,
                         unordered_map<char, int> &translation) {
    int i = 0;
    while (i < min(word1.size(), word2.size())) {
      if (translation[word1[i]] < translation[word2[i]]) {
        return -1;
      } else if (translation[word1[i]] > translation[word2[i]]) {
        return 1;
      }
      ++i;
    }
    if (i < word1.size()) {
      return 1;
    }
    if (i < word2.size()) {
      return -1;
    }
    return 0;
  }
};
