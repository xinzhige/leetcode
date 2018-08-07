// Recursive
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> sub;
    dfs(nums, 0, sub, result);
    return result;
  }

private:
  void dfs(vector<int> &nums, int start, vector<int> &sub, vector<vector<int>> &result) {
    result.push_back(sub);
    for (int i = start; i < nums.size(); ++i) {
      sub.push_back(nums[i]);
      dfs(nums, i + 1, sub, result);
      sub.pop_back();
    }
  }
};


// Iterative
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result(1);
    for (const auto &num : nums) {
      int n = result.size();
      for (int i = 0; i < n; ++i) {
        result.push_back(result[i]);
        result.back().push_back(num);
      }
    }
    return result;
  }
};
