class Solution {
public:
  int longestValidParentheses(string s) {
    int max_len = 0;
    // Use a variable last to store the last non-matching ')'
    int last = -1;
    // Use a stack to store the non-matching '(' and
    stack<int> lefts;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] =='(') {
	lefts.push(i);
      } else {
	if (lefts.empty()) {
	  last = i;
	} else {
	  lefts.pop();
	  if (lefts.empty()) {
	    max_len = max(max_len, i-last);
	  } else {
	    max_len = max(max_len, i-lefts.top());
	  }
	}
      }
    }
    return max_len;
  }
};
