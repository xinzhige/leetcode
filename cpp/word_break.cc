class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> result(s.size() + 1, false);
    unordered_map<string, bool> mymap;
    for (const auto & word : wordDict) {
      mymap[word] = true;
    }
    result[0] = true;
    for (int i = 0; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
	if (result[j] && mymap.count(s.substr(j, i-j))) {
	  result[i] = true;
	  break;
	}
      }
    }
    return result[s.size()];
  }
};
