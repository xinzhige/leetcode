class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> maps;
    unordered_map<char, int> mapt;
    if (s.size() != t.size()) {
      return false;
    }
    for (int i = 0; i < s.size(); i++) {
      if (maps[s[i]] != mapt[t[i]]) {
        return false;
      }
      // If the map does not contain current character, the operator [] would
      // return 0 so use i + 1 instead of i.
      maps[s[i]] = i + 1;
      mapt[t[i]] = i + 1;
    }
    return true;
  }
};
