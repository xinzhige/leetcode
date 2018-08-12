// Recursive
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> sub;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    sub(nums, 0, sub, result);
    return result;
  }
  void dfs(vector<int> &s, int start, vector<int> &sub,
           vector<vector<int>> &result) {
    result.push_back(sub);
    for (int i = start; i < s.size(); ++i) {
      if (i == start || s[i] != s[i - 1]) {
        sub.push_back(s[i]);
        dfs(s, i + 1, sub, result);
        sub.pop_back();
      }
    }
  }
};


// Iterative
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {{}, {nums[0]}};
    vector<vector<int>> sub = {{nums[0]}};
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i-1]) {
        sub = result;
      }
      for (auto &s : sub) {
        s.push_back(nums[i]);
      }
      result.insert(result.end(), sub.begin(), sub.end());
    }
    return result;
  }
};
