class Solution {
public:
  bool isPalindrome(string& s, int begin, int end) {
    while (begin < end) {
      if (s[begin] != s[end]) {
        return false;	      
      }	   
      begin += 1;
      end -= 1;
    }	 
    return true;
  }
  void partitionHelper(string& s, int start, vector<string>& out, vector<vector<string> >& result) {
    if (start == s.size()) {
      result.push_back(out);
      return;
    }	 
    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        out.push_back(s.substr(start, i - start + 1));
        partitionHelper(s, i + 1, out, result);
	out.pop_back();
      }	    
    }
  }
  vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    vector<string> out;
    partitionHelper(s, 0, out, result);
    return result;
  }
};
