class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int kMaxChars = 256;
    vector<int> mymap(kMaxChars, -1);
    int max_len = 0;
    int last_repeat_pos = -1;
    for (int i = 0; i < s.size(); i++) {
      if (mymap[s[i]] != -1 && last_repeat_pos < mymap[s[i]]) {
        last_repeat_pos = mymap[s[i]];	      
      }	   
      int curr_len = i - last_repeat_pos;
      if (curr_len > max_len) {
        max_len = curr_len;	      
      }
      mymap[s[i]] = i; 
    }
    return max_len;
  }
};
