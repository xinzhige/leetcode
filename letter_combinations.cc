// recursive
class Solution {
public:
  const vector<string> keyboard { "0", "1", "abc", "def", 
      "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
  vector<string> letterCombinations (const string &digits) {
    vector<string> result;
    dfs(digits, 0, "", result);
    return result;
  }
  void dfs(const string &digits, size_t curr, string path, vector<string> &result) {
    if (curr == digits.size()) {
      result.push_back(path);
      return;
    }
    for (auto c : keyboard[digits[curr] - '0']) {
      dfs(digits, curr + 1, path + c, result);
    }
  }
};

// iterative
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      const string letters[] = {"0", "1", "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
      vector<string> ret(1, "");
      for (int i = 0; i < digits.size(); ++i) {
        const string &s = letters[digits[i] - '0'];
    	for (int j = ret.size() - 1; j >= 0; --j) {
    	  for (int k = s.size() - 1; k >= 0; --k) {
    	    if (k > 0) {
    	      ret.push_back(ret[j] + s[k]);
    	    } else {
    	      ret[j] += s[k];
    	    }
    	  }
    	}
      }  
      return ret;
    }
};
