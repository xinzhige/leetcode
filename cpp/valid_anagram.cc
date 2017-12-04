class Solution {
public:
  bool isAnagram(string s, string t) {
    size_t s_len = s.size();
    size_t t_len = t.size();
    if (s_len != t_len) {
      return false;
    }
    unordered_map<char, int> mymap;
    for (int i = 0; i < s_len; i++) {
      if (mymap.find(s[i]) == mymap.end()) {
        mymap[s[i]] = 1;
      } else {
        mymap[s[i]] += 1;
      }
    }
    for (int i = 0; i < t_len; i++) {
      if (mymap.find(t[i]) == mymap.end()) {
        return false;
      } else {
        mymap[t[i]] -= 1;
      }
    }
    unordered_map<char, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++) {
      if (it->second != 0) {
        return false;
      }
    }
    return true;
  }
};
