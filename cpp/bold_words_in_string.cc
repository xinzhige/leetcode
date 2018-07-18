// By array, time: O(n*sum(wi)), space: O(n)
class Solution {
public:
  string boldWords(vector<string>& words, string S) {
    int n = S.size();
    vector<bool> bold(n, false);
    for (const auto &w : words) {
      int len = w.size();
      for (int i = 0; i <= n - len; ++i) {
        if (w[0] == S[i] && S.substr(i, len) == w) {
          for (int j = i; j < i + len; ++j) {
            bold[j] = true;
          }
        }
      }
    }
    string result("");
    for (int i = 0; i < n; ++i) {
      if (bold[i]) {
        if (i == 0 || !bold[i - 1]) {
          result += "<b>";
        }
        result += S[i];
        if (i == n - 1 || !bold[i + 1]) {
          result += "</b>";
        }
      } else {
        result += S[i];
      }
    }
    return result;
  }
};


// By set
class Solution {
public:
  string boldWords(vector<string>& words, string S) {
    int n = S.size();
    unordered_set<int> bold;
    for (const auto &w : words) {
      int len = w.size();
      for (int i = 0; i <= n - len; ++i) {
        if (w[0] == S[i] && S.substr(i, len) == w) {
          for (int j = i; j < i + len; ++j) {
            bold.insert(j);
          }
        }
      }
    }
    string result("");
    for (int i = 0; i < n; ++i) {
      if (bold.count(i) > 0 && bold.count(i-1) == 0) {
        result += "<b>";
      }
      result += S[i];
      if (bold.count(i) > 0 && bold.count(i+1) == 0) {
        result += "</b>";
      }
    }
    return result;
  }
};
