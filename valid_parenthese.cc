class Solution {
public:
  bool isValid(string s) {
    stack<char> my_stack;
    int str_size = s.size();
    for (int i = 0; i < str_size; ++i) {
      if (s[i] == '(' || s[i] == '[' ||
	    s[i] == '{') {
	    my_stack.push(s[i]);
      } else {
	    if (my_stack.empty()) {   // in case there are ')', ']' or '}' before their parentheses
	      return false;
	    }
	    char curr_top = my_stack.top();
	    if ((s[i] == ')' && curr_top == '(') ||
	        (s[i] == ']' && curr_top == '[') ||
	        (s[i] == '}' && curr_top == '{')) {
	      my_stack.pop();
	    } else {
	      return false;
	    }
      }
    }
    return my_stack.empty();
  }
};
