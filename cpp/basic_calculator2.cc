/*
 * Idea: think of 2-1 as 2+(-1), use two variables sign and num to represent * previous sign and current number. If sign is '+' or '-', push num into
 * stack. If sign is '*' or '/', calculate previous number(stack top) and
 * num and push its result into stack. Finally, sum all the elements in stack.
 */
class Solution {
public:
  int calculate(string s) {
    stack<int> st;  // all the numbers calculated by -, * or /
    int num = 0;    // current number calculated by * and /
    char sign = '+';  // the previous operator
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        int curr_digit = s[i] - '0'
        num = 10 * num + curr_digit;
      }
      if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
        if (sign == '+') {
          st.push(num);
        }
        if (sign == '-') {
          st.push(-num);
        }
        if (sign == '*') {
          num = st.top() * num;
          st.pop();
          st.push(num);
        }
        if (sign == '/') {
          num = st.top() / num;
          st.pop();
          st.push(num);
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
