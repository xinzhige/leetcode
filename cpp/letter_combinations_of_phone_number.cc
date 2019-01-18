// Backtracking
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
  void backtrack(const string &digits, int level, string path,
                 vector<string> &result) {
    if (level == digits.size()) {
      result.push_back(path);
      return;
    }
    string str = keyboard[digits[level] - '2'];
    for (const char &c : str) {
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


// Iterative
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> result;
    result.push_back("");
    for (const char &d : digits) {
      vector<string> tmp;
      int i = d - '2';
      for (const string &s : result) {
        for (const char &c : keyboard[i]) {
          tmp.push_back(s + c);
        }
      }
      result = tmp;
    }
    return result;
  }

private:
  const vector<string> keyboard = {"abc", "def",
                                   "ghi", "jkl", "mno",
                                   "pqrs", "tuv", "wxyz"};
};
