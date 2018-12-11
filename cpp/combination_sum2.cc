class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> path;
    backtrack(candidates, 0, target, path, result);
    return result;
  }

private:
  void backtrack(vector<int> &nums, int pos, int target,
                 vector<int> &path, vector<vector<int>> &result) {
    if (target == 0) {
      result.push_back(path);
    } else {
      for (int i = pos; i < nums.size(); ++i) {
        if (target < nums[i]) {
          return;
        }
        if (i == pos || nums[i] != nums[i-1]) {
          path.push_back(nums[i]);
          backtrack(nums, i + 1, target - nums[i], path, result);
          path.pop_back();
        }
      }
    }
  }
};
