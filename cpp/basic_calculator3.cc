class Solution {
public:
  int calculate(string s) {
    long level1 = 0;
    long operator1 = 1;
    long level2 = 1;
    long operator2 = 1;
    stack<long> st;
    int n = s.size();
    long num = 0;
    for (int i = 0; i < n; i++) {
      if (isdigit(s[i])) {
        num = s[i] - '0';
        for (; i + 1 < n && isdigit(s[i + 1]); ++i) {
          num = num * 10 + (s[i + 1] - '0');
        }
        level2 = (operator2 == 1 ? level2 * num : level2 / num);
      } else if (s[i] == '(') {
        st.push(level1);
        st.push(operator1);
        st.push(level2);
        st.push(operator2);
        level1 = 0;
        operator1 = 1;
        level2 = 1;
        operator2 = 1;
      } else if (s[i] == ')') {
        num = level1 + operator1 * level2;
        operator2 = st.top();
        st.pop();
        level2 = st.top();
        st.pop();
        operator1 = st.top();
        st.pop();
        level1 = st.top();
        st.pop();
        level2 = (operator2 == 1 ? level2 * num : level2 / num);
      } else if (s[i] == '*' || s[i] == '/') {
        operator2 = (s[i] == '*' ? 1 : -1);
      } else if (s[i] == '+' || s[i] == '-') {
        level1 = level1 + operator1 * level2;
        operator1 = (s[i] == '+' ? 1 : -1);
        level2 = 1;
        operator2 = 1;
      }
    }
    return int(level1 + operator1 * level2);
  }
};
