class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int left = 0;
    int result = 0; 
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.size(); ++i) {
      mymap[s[i]] += 1; 
      while (mymap.size() > k) {
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
