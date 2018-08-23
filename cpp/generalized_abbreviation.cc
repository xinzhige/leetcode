class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> result;
    backtrack(word, "", 0, false, result);
    return result;
  }
  void backtrack(string& word, string abbr, int pos, bool prevNum,
                 vector<string>& result) {
    if (pos == word.length()) {
      result.push_back(abbr);
    } else {
      backtrack(word, abbr + word[pos], pos + 1, false, result);
      if (!prevNum) {
        for (int len = 1; pos + len <= word.length(); ++len) {
          backtrack(word, abbr + to_string(len), pos + len, true, result);
        }
      }
    }
  }
};


// Bit manipulation
class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> result;
    int n = pow(2, word.size());
    for (int i = 0; i < n; ++i) {
      string out("");
      int count = 0;
      for (int j = 0; j < word.size(); ++j) {
        if ((i >> j) & 1) {
          count += 1;
        } else {
          if (count != 0) {
            out += to_string(count);
            count = 0;
          }
          out += word[j];
        }
      }
      if (count > 0) {
        out += to_string(count);
      }
      result.push_back(out);
    }
    return result;
  }
};
