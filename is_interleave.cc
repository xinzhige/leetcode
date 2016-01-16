class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
    	size_t s1_length = s1.size();
  		size_t s2_length = s2.size();
  		if (s1.size() + s2.size() != s3.size()) {
  			return false;
  		}
  		if (s1_length < s2_length) {
  			return isInterleave(s2, s1, s3);
  		}
  		vector<bool> match(s2_length+1, true);
  		for (size_t i = 1; i <= s2_length; ++i) {
  			match[i] = match[i-1] && s2[i-1] == s3[i-1];
  		}
  		for (size_t i = 1; i <= s1_length; ++i) {
  			match[0] = match[0] && s1[i-1] == s3[i-1];
  			for (size_t j = 1; j <= s2_length; ++j) {
  				match[j] = (match[j] && s1[i-1] == s3[i+j-1]) ||
  					       (match[j-1] && s2[j-1] == s3[i+j-1]); 
  			}
  		}
  		return match[s2_length];
  }
};