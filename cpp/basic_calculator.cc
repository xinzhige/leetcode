class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    int result = 0;
    int num = 0;  // current number
    int sign = 1;  // previous sign
    for (const char &c : s){
      if (isdigit(c)) {
        num = 10 * num + (c - '0');
      } else if (c == '+') {
        result += sign * num;
        num = 0;
        sign = 1;
      } else if (c == '-') {
        result += sign * num;
        num = 0;
        sign = -1;
      } else if (c == '(') {
        st.push(result);
        st.push(sign);
        sign = 1;
        result = 0;
      } else if (c == ')') {
        result += sign * num;
        num = 0;
        result *= st.top();
        st.pop();
        result += st.top();
        st.pop();
      }
    }
    // Note: do not forget to add the last number
    result += sign * num;
    return result;
  }
