class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> mymap;
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      mymap[s[i]] += 1;
      if ((mymap[s[i]] % 2) != 0) {
        result += 1;
      } else {
        result -= 1;
      }
    }
    return result <= 1;
  }
};
