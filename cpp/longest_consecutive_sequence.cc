class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> used;
    for (const int &x : nums) {
      used.insert(x);
    }
    int result = 0;
    for (const int &x : used) {
      if (used.count(x - 1) == 0) {
        int curNum = x;
        int curLen = 1;
        while (used.count(curNum + 1) > 0) {
          curNum += 1;
          curLen += 1;
        }
        result = max(result, curLen);
      }
    }
    return result;
  }
};
