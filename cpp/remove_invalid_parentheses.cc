class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> visited;
    visited.insert(s);
    queue<string> q;
    q.emplace(s);
    bool found = false;
    vector<string> result;
    while (!q.empty()) {
      string t = q.front();
      q.pop();
      if (isValid(t)) {
        result.push_back(t);
        found = true;
      }
      if (!found) {
        for (int i = 0; i < t.size(); ++i) {
          if (t[i] == '(' || t[i] == ')') {
            string str = t.substr(0, i) + t.substr(i + 1);
            if (visited.count(str) == 0) {
              q.push(str);
              visited.insert(str);
            }
          }
        }
      }
    }
    return result;
  }
  bool isValid(const string &s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        count += 1;
      } else if (s[i] == ')') {
        count -= 1;
        if (count < 0) {
          return false;
        }
      }
    }
    return count == 0;
  }
};


class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    backtrack(s, 0, 0, "()", result);
    return result;
  }
  // last_i: current position, last_j: last character deleted
  void backtrack(const string &s, int last_i, int last_j, const string &p,
                 vector<string>& result) {
    int count = 0;
    for (int i = last_i; i < s.size(); ++i) {
      if (s[i] == p[0]) {
        count += 1;
      } else if (s[i] == p[1]) {
        count -= 1;
      }
      if (count < 0) {
        for (int j = last_j; j <= i; ++j) {
          if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
            backtrack(s.substr(0, j) + s.substr(j + 1), i, j, p, result);
          }
        }
        return;
      }
    }
    string rev = string(s.rbegin(), s.rend());
    if (p[0] == '(') {
      backtrack(rev, 0, 0, ")(", result);
    } else {
      result.push_back(rev);
    }
  }
};
