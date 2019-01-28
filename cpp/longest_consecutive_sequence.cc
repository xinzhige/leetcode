// Time: O(n), space: O(n)
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


// Time: O(nlogn), space: O(1)
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int result = 1;
    int curLen = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] != nums[i]) {
        if (nums[i] == nums[i - 1] + 1) {
          curLen += 1;
        } else {
          result = max(result, curLen);
          curLen = 1;
        }
      }
    }
    result = max(result, curLen);
    return result;
  }
};
