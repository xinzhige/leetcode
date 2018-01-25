class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, bool> mymap;
    for (const auto & c : s) {
      if (mymap.count(c)) {
	mymap[c] = false;
      } else {
	mymap[c] = true;
      }
    }
    for (int i = 0; i < s.size(); ++i) {
      if (mymap[s[i]]) {
	return i;
      }
    }
    return -1;
  }
};
