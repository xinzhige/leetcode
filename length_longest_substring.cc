class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int s_length = s.size();
    int left = 0, right = 0;
    int max_len = 0;
    bool existed[256] = { false };
    while (right < s_length) {
      if (existed[s[right]]) {
	max_len = max(max_len, right-left);
	while (s[left] != s[right]) {
	  existed[s[left]] = false;
	  left++;
	}
	left++;
      } else {
	existed[s[right]] = true;
      }
      right++;
    }
    max_len = max(max_len, s_length-left);
    return max_len;
  }
};
