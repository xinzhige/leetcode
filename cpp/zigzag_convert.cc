class Solution {
public:
  string convert(string s, int nRows) {
    if(nRows <= 1) {
      return s;
    }
    string result;
    int zig_size = 2 * nRows - 2;
    for(int i = 0; i < nRows; ++i) {
      for(int base = i; base < s.size(); base += zig_size) {
        // base the char at odd point in each row
	result.push_back(s[base]);
	if(i > 0 && i < nRows - 1) {
          // zig_size - 2 * i is the gap between neighbor chars at odd points and even point
	  int ti = base + zig_size - 2 * i;
	  if(ti < s.size()) {
	    result.push_back(s[ti]);
	  }
	}
      }
    }
    return result;
  }
};
