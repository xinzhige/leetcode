class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, result);
    return result;
  }
private:
  void dfs(vector<int> nums, int start, vector<vector<int> > &result) {
    if (start == nums.size() - 1) {
      result.push_back(nums);
    } else {
      for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i] != nums[start]) {
          swap(nums[i], nums[start]);
          dfs(nums, start + 1, result);
        }
      }
    }
  }
};


// With set
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> result;
    permute(nums, 0, result);
    return vector<vector<int>> (result.begin(), result.end());
  }
  void permute(vector<int> &nums, int start, set<vector<int>> &result) {
    if (start >= nums.size()) {
      result.insert(nums);
    }
    for (int i = start; i < nums.size(); ++i) {
      if (i != start && nums[i] == nums[start]) {
        continue;
      }
      swap(nums[i], nums[start]);
      permute(nums, start + 1, result);
      swap(nums[i], nums[start]);
    }
  }
};
