class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> count;
    for (const auto &c : s) {
      count[c] += 1;
    }
    for (const auto &c : t) {
      count[c] -= 1;
    }
    for (auto it = count.begin(); it != count.end(); ++it) {
      if (it->second != 0) {
        return it->first;
      }
    }
    return ' ';
  }
};


// By bit manipulation
class Solution {
public:
  char findTheDifference(string s, string t) {
    int n = t.size();
    char c = t[n - 1];
    for (int i = 0; i < n - 1; ++i) {
      c ^= s[i];
      c ^= t[i];
    }
    return c;
  }
};
