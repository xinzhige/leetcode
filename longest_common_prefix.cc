class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if(strs.empty()) {
      return "";
    }
    int num_strings = strs.size();
    int len_first_string = strs[0].size();
    for(int j = 0; j < len_first_string; ++j){
      for(int i = 1; i < num_strings; ++i){
    	if(strs[i][j] != strs[i-1][j]){
    	  return strs[0].substr(0, j);
    	}
      }
    }
    return strs[0];
  }
};

// use divide-and-conquer to reduce time to O(lg(m+n)), where m is the number of strings and n is the length of the shortest string
class Solution {
public:
  bool isEqual(vector<string> &strs, int index, int start, int end) {
    if(end < start) {
      return true;
    }
    if(end == start) {
      if(strs[start].size() > index) {
	    return true;
      } else {
	    return false;
      }
    }
    int mid = start + (end - start) / 2;
    bool lEqual = isEqual(strs, index, start, mid);
    bool rEqual = isEqual(strs, index, mid + 1, end);
    if(!lEqual || !rEqual) {
      return false;
    }
    if(index > strs[start].size() || index > strs[end].size() || 
        strs[start][index] != strs[end][index]) {
      return false;
    }
    return true;
  }
  string longestCommonPrefix(vector<string> &strs) {
    string result;
    int num_strings = strs.size();
    if(0 == num_strings) {
      return result;
    }
    if(1 == num_strings) {
      return strs[0];
    }
    int len = 0;
    while(isEqual(strs, len, 0, num_strings - 1)) {
      ++len;
    }
    result = strs[0].substr(0, len);
    return result;
  }
};
