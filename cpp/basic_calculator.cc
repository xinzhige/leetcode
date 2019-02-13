class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    int result = 0;
    int num = 0;  // current number
    int sign = 1;  // previous sign
    int n = s.size();
    for (int i = 0; i < n; ++i){
      if (isdigit(s[i])) {
        num = 10 * num + (s[i] - '0');
      } else if (s[i] == '+') {
        result += sign * num;
        num = 0;
        sign = 1;
      } else if (s[i] == '-') {
        result += sign * num;
        num = 0;
        sign = -1;
      } else if (s[i] == '(') {
        st.push(result);
        st.push(sign);
        sign = 1;
        result = 0;
      } else if (s[i] == ')') {
        result += sign * num;
        num = 0;
        result *= st.top();
        st.pop();
        result += st.top();
        st.pop();
      }
    }
    result += sign * num;
    return result;
  }
