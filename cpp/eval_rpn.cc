class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    int result = 0;
    int left_val = 0;
    int right_val = 0;
    stack<int> mystack;
    for (auto & s : tokens) {
      if (is_operator(s)) {
        right_val = mystack.top();
        mystack.pop();
        left_val = mystack.top();
        mystack.pop();
        result = operation(left_val, right_val, s);
        mystack.push(result);
      } else {
        mystack.push(stoi(s));
      }
    }
    return mystack.top();
  }
  bool is_operator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
  }
  int operation(int left, int right, string s) {
    if (s == "+") {
      return left + right;
    } else if (s == "-") {
      return left - right;
    } else if (s == "*") {
      return left * right;
    } else {
      return left / right;
    }
  }
};
