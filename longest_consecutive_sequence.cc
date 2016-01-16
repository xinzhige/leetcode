class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_map<int,bool> used;
    for (auto x : num) {
      used[x] = false;
    }
    int result = 0;
    for (auto curr : num) {
      if (used[curr]) {
	    continue;
      }
      int max = 1;      
      used[curr] = true;
      for (int i = curr + 1; used.find(i) != used.end(); ++i) {
    	used[i] = true;
    	++max;
      }
      for (int i = curr - 1; used.find(i) != used.end(); --i) {
    	used[i] = true;
    	++max;
      }
      if (max > result) {
	    result = max;
      }
    }
    return result;
  }
};
