class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int l = 0;  // the left of the sliding window
    int r = -1;  // the right of the sliding window (the end of the substring to be deleted) 
    int len = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        if (r >= 0 && s[i] != s[r]) {  // s[i], s[i - 1] and s[r] are mutually different
          len = max(len, i - l); 
          l = r + 1;
        }
        r = i - 1;   // s[r] is not equal to elements in between r and i
      }
    }
    return max(n - l, len);  
  }
};


// Hash table
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int result = 0;
    int left = 0;
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.size(); ++i) {
      mymap[s[i]] += 1;
      while (mymap.size() > 2) {
        mymap[s[left]] -= 1; 
        if (mymap[s[left]] == 0) {
          mymap.erase(s[left]); 
        }
        left += 1;
      }
      result = max(result, i - left + 1);
    }
    return result;
  }
};
