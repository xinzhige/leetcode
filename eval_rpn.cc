class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<string> numbers;
    for (string token : tokens) {
      if (!is_operator(token)) {
	numbers.push(token);
      } else {
	int y = stoi(numbers.top());
	numbers.pop();
	int x = stoi(numbers.top());
	numbers.pop();
	if (token[0] == '+') {
	  x += y;
	} else if (token[0] == '-') {
	  x -= y;
	} else if (token[0] == '*') {
	  x *= y;
	} else {
	  x /= y;
	}
	numbers.push(to_string(x));
      }
    }
    return stoi(numbers.top());
  }
private:
  bool is_operator(const string &op) {
    string signs("+-*/");
    return op.size() == 1 && signs.find(op) != string::npos;
  }
};
