class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int slen = s.size();
    int plen = p.size();
    vector<int> scount(256, 0);
    vector<int> pcount(256, 0);
    for (int i = 0; i < plen; ++i) {
      scount[s[i]] += 1;
      pcount[p[i]] += 1;
    }
    if (scount == pcount) {
      result.push_back(0);
    }
    for (int i = plen; i < slen; ++i) {
      scount[s[i]] += 1;
      scount[s[i - plen]] -= 1;
      if (scount == pcount) {
        result.push_back(i - plen + 1);
      }
    }
    return result;
  }
};
