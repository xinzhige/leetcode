class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> tmp;
    backtrack(candidates, 0, target, tmp, result);
    return result;
  }

private:
  void backtrack(vector<int> &nums, int pos, int target,
                 vector<int> &tmp, vector<vector<int>> &result) {
    if (target == 0) {
      result.push_back(tmp);
    } else {
      for (int i = pos; i < nums.size(); ++i) {
        if (target < nums[i]) {
          return;
        }
        if (i == pos || nums[i] != nums[i-1]) {
          tmp.push_back(nums[i]);
          backtrack(nums, i + 1, target-nums[i], tmp, result);
          tmp.pop_back();
        }
      }
    }
  }
};
