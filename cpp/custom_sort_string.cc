class Solution {
public:
  string customSortString(string S, string T) {
    set<char> charset(S.begin(), S.end());
    unordered_map<char, int> freq;
    for (const auto &c : T) {
      if (charset.count(c) > 0) {
        freq[c] += 1;
      }
    }
    string result("");
    int idx = 0;
    for (int i = 0; i < S.size(); ++i) {
      for (int j = 0; j < freq[S[i]]; ++j) {
        result.push_back(S[i]);
      }
    }
    for (int i = 0; i < T.size(); ++i) {
      if (freq.count(T[i]) == 0) {
        result.push_back(T[i]);
      }
    }
    return result;
  }
};
