class Solution {
public:
  string parseTernary(string e) {
    stack<char> s;
    for (int i = e.size() - 1; i >= 0; --i) {
      char c = e[i];
      if (!s.empty() && s.top() == '?') {
        s.pop();
        char first = s.top();
        s.pop();
        s.pop();
        char second = s.top();
        s.pop();
        s.push(c == 'T' ? first : second);
      } else {
        s.push(c);
      }
    }
    return string(1, s.top());
  }
};
