class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &nums) {
    set<vector<int>> result;
    sort(nums.begin(), nums.end());
    backtrack(nums, 0, result);
    return vector<vector<int>> (result.begin(), result.end());
  }
  void backtrack(vector<int> nums, int start, set<vector<int>> &result) {
    if (start == nums.size()) {
      result.insert(nums);
    } else {
      for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i - 1] != nums[i]) {
          swap(nums[i], nums[start]);
          backtrack(nums, start + 1, result);
          swap(nums[i], nums[start]);
        }
      }
    }
  }
};
