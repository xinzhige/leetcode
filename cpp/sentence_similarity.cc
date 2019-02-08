class Solution {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2,
                           vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) {
      return false;
    }
    set<string> pairset;
    for (const auto &p : pairs) {
      pairset.insert(p.first + "-" + p.second);
    }
    for (int i = 0; i < words1.size(); ++i) {
      if (words1[i] != words2[i] &&
          pairset.count(words1[i] + "-" + words2[i]) == 0 &&
          pairset.count(words2[i] + "-" + words1[i]) == 0) {
        return false;
      }
    }
    return true;
  }
};
