// DFS
class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    return decode(s, i);
  }
  string decode(string s, int& i) {
    string result = "";
    int n = s.size();
    while (i < n && s[i] != ']') {
      if (!isdigit(s[i])) {
        result += s[i];
        ++i;
      } else {
        int count = 0;
        for (; i < n && isdigit(s[i]); ++i) {
          count = count * 10 + s[i] - '0';
        }
        ++i;
        string t = decode(s, i);
        ++i;
        for (; count > 0; --count) {
          result += t;
        }
      }
    }
    return result;
  }
};


// Iterative algorithm by two stacks
class Solution {
public:
  string decodeString(string s) {
    string t = "";
    stack<int> s_num;
    stack<string> s_str;
    int count = 0;
    for (const auto &c : s) {
      if (isdigit(c)) {
        count = 10 * count + c - '0';
      } else if (isalpha(c)) {
        t += c;
      } else if (c == '[') {
        s_num.push(count);
        s_str.push(t);
        count = 0;
        t = "";
      } else if (c == ']') {
        int n = s_num.top();
        s_num.pop();
        for (int i = 0; i < n; ++i) s_str.top() += t;
        t = s_str.top();
        s_str.pop();
      }
    }
    return s_str.empty() ? t : s_str.top();
  }
};
