class Solution {
public:
  int calculate(string s) {
    stack<int> st;  // Store all the numbers calculated by -, * or /
    int num = 0;
    char sign = '+';  // Store the previous operator
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        num = 10 * num + (s[i] - '0');
      }
      if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
        if (sign == '+') {
          st.push(num);
        }
        if (sign == '-') {
          st.push(-num);
        }
        int tmp = 0;
        if (sign == '*') {
          tmp = st.top() * num;
          st.pop();
          st.push(tmp);
        }
        if (sign == '/') {
          tmp = st.top() / num;
          st.pop();
          st.push(tmp);
        }
        sign = s[i];
        num = 0;
      }
    }
    int result = 0;
    for (; !st.empty(); st.pop()) {
      result += st.top();
    }
    return result;
  }
};
