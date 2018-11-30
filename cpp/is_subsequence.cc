// Idea: two pointers
class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) {
      return true;
    }
    int i = 0;
    for (int j = 0; j < t.size(); ++j) {
      if (t[j] == s[i]) {
        ++i;
      }
    }
    return i == s.size();
  }
};


// Follow-up
class Solution {
public:
  bool isSubsequence(string s, string t) {
    unordered_map<char, vector<int>> index;
    for (int i = 0; i < t.size(); ++i) {
      index[t[i]].push_back(i);
    }
    int curr = -1;
    for (const char &c : s) {
      if (index.count(c) == 0) {
        return false;
      }
      vector<int> arr = index[c];
      auto it = upper_bound(arr.begin(), arr.end(), curr);
      if (it == arr.end()) {
        return false;
      }
      curr = *it;
    }
    return true;
  }
};
