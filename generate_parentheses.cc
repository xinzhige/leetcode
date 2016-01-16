class Solution {
public:
  void addParenthesis(vector<string> &list, string str, int left_remain, 
		      int right_remain) {
    if (left_remain == 0 && right_remain == 0) {
      list.push_back(str);
      return;
    } else {
      if (left_remain > 0) {
	addParenthesis(list, str + '(', left_remain - 1, right_remain);
      }
      if (right_remain > left_remain) {
	addParenthesis(list, str + ')', left_remain, right_remain - 1);
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
