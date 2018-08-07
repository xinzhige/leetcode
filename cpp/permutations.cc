// Time: O(n!), space: O(1)
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    dfs(nums, 0, result);
    return result;
  }
  void dfs(vector<int> &nums, int pos, vector<vector<int>> &result) {
    if(pos == nums.size()) {
      result.push_back(nums);
    } else {
      for(int i = pos; i < nums.size(); ++i) {
        swap(nums[i], nums[pos]);
        dfs(nums, pos + 1, result);
        swap(nums[i], nums[pos]);
      }
    }
  }
};
