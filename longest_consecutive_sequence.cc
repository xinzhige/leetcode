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
      int curr_max = 1;
      used[curr] = true;
      for (int i = curr + 1; used.find(i) != used.end(); ++i) {
        used[i] = true;
        ++curr_max;
      }
      for (int i = curr - 1; used.find(i) != used.end(); --i) {
        used[i] = true;
        ++curr_max;
      }
      result = max(curr_max, result);
    }
    return result;
  }
};
