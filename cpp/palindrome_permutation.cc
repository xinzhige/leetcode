class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> mymap;
    for (auto &c : s) {
      mymap[c] += 1;
    }
    int result = 0;
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
      if (iter.second % 2 != 0) {
        result += 1;
      }
    }
    return result <= 1;
  }
};
