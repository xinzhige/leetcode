class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, result);
    return result;
  }
  void dfs(vector<int> nums, int start, vector<vector<int> > &result) {
    if (start == nums.size() - 1) {
      result.push_back(nums);
    } else {
      for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i] != nums[start]) {
          swap(nums[i], nums[start]);
          dfs(nums, start + 1, result);
          swap(nums[i], nums[start]);
        }
      }
    }
  }
};
