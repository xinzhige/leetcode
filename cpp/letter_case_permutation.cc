// Backtracking
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> result;
    backtrack(S, 0, result);
    return result;
  }
  void backtrack(string &S, int i, vector<string> &result) {
    if (i == S.size()) {
      result.push_back(S);
      return;
    }
    backtrack(S, i + 1, result);
    if (isalpha(S[i])) {
      S[i] ^= (1 << 5);
      backtrack(S, i + 1, result);
    }
  }
};


// Iterative
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> result{""};
    for (const auto &c : S) {
      int len = result.size();
      if (c >= '0' && c <= '9') {
        for (auto &str : result) {
          str.push_back(c);
        }
      } else {
        for (int i = 0; i < len; ++i) {
          result.push_back(result[i]);
          result[i].push_back(c);
          result[len + i].push_back(c ^ (1 << 5));
        }
      }
    }
    return result;
  }
};
