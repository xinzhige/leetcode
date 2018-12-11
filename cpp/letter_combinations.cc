class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
      return result;
    }
    backtrack(digits, 0, "", result);
    return result;
  }
  void backtrack(const string &digits, int level, string path, vector<string> &result) {
    if (level == digits.size()) {
      result.push_back(path);
      return;
    }
    string str = keyboard[digits[level] - '2'];
    for (char &c : str) {
      path.push_back(c);
      backtrack(digits, level + 1, path, result);
      path.pop_back();
    }
  }

private:
  const vector<string> keyboard = {"abc", "def",
                                   "ghi", "jkl", "mno",
                                   "pqrs", "tuv", "wxyz" };
};

// iterative
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
      return result;
    }
    result.emplace_back("");
    for (int i = 0; i < digits.size(); ++i) {
      int n = result.size();
      string str = keyboard[digits[i] - '2'];
      for (int j = 0; j < n; ++j) {
        string tmp = result.front();
        result.erase(result.begin());
        for (int k = 0; k < str.size(); ++k) {
          result.emplace_back(tmp + str[k]);
        }
      }
    }
    return result;
  }

private:
  const vector<string> keyboard = {"abc", "def",
                               "ghi", "jkl", "mno",
                               "pqrs", "tuv", "wxyz"};
};
