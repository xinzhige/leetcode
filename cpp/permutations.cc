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


// Iterative
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    vector<vector<int>> result;
    vector<int> sub;
    sub.push_back(nums[0]);
    result.push_back(sub);
    for (int i = 1; i < nums.size(); ++i) {
      int n = result.size();
      for (int j = 0; j < n; ++j) {
        int m = result[0].size();
        for (int k = 0; k <= m; ++k) {
          vector<int> temp = result[0];
          temp.insert(temp.begin() + k, nums[i]);
          result.push_back(temp);
        }
        result.erase(result.begin());
      }
    }
    return result;
  }
};
