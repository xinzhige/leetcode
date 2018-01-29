class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    int left = 0;
    int right = 0;
    stack<int> nums;
    for (const auto &t : tokens) {
      if (isOperator(t)) {
        right = nums.top();
        nums.pop();
        left = nums.top();
        nums.pop();
        nums.push(operation(left, right, t));
      } else {
        nums.push(stoi(t));
      }
    }
    return nums.top();
  }
  bool isOperator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
  }
  int operation(const int &left, const int &right, const string &s) {
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
