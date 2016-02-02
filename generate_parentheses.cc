class Solution {
public:
  void addParenthesis(vector<string> &list, string str, int left, 
		      int right) {
    if (left == 0 && right == 0) {
      list.push_back(str);
      return;
    } else {
      if (left > 0) {
	addParenthesis(list, str + '(', left - 1, right);
      }
      if (right > left) {
	addParenthesis(list, str + ')', left, right - 1);
      }
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> list;
    string str;
    addParenthesis(list, str, n, n);
    return list;
  }
};
