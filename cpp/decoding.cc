class Solution {
public:
  int numDecodings(string s) {
    size_t s_length = s.size();
    if (s_length == 0) {
      return 0;
    }
    size_t prev = 0;
    size_t curr = 1;
    for (size_t i = 0; i < s_length; ++i) {
      if (s[i] == '0') {
	curr = 0;
      }
      if (i < 1 || !(s[i-1] == '1' || 
		     (s[i-1] == '2' && s[i] <= '6'))) {
	prev = 0;
      }
      size_t temp = curr;
      curr += prev;
      prev = temp;
    }
    return curr;
  }
};
