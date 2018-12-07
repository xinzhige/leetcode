class Solution {
public:
  bool isAnagram(string s, string t) {
    map<char, int> freq;
    for (const char &c : s) {
      freq[c] += 1;
    }
    for (const char &c : t) {
      if (freq.count(c) == 0) {
        return false;
      } else {
        freq[c] -= 1;
        if (freq[c] == 0) {
          freq.erase(c);
        }
      }
    }
    return freq.empty();
  }
};
