// Idea: go through each word in str and compare it to the corresponding
// letter in pattern. Use two hash-table to store the index of them.
class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, int> c2i;
    unordered_map<string, int> w2i;
    istringstream is(str);
    int i = 0;
    int n = pattern.size();
    for (string word = ""; is >> word; ++i) {
      if (i == n || c2i[pattern[i]] != w2i[word]) {
        return false;
      }
      c2i[pattern[i]] = i + 1;
      w2i[word] = i + 1;
    }
    return i == n;
  }
};
