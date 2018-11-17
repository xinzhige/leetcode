// DFS
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> out;
    dfs(nums, 0, out, result);
    return result;
  }
  void dfs(vector<int>& nums, int start, vector<int>& out,
           vector<vector<int>>& result) {
    if (out.size() >= 2) {
      result.push_back(out);
    }
    unordered_set<int> st;
    for (int i = start; i < nums.size(); ++i) {
      if (!out.empty() && out.back() > nums[i] || st.count(nums[i]) > 0) {
        continue;
      }
      out.push_back(nums[i]);
      st.insert(nums[i]);
      dfs(nums, i + 1, out, result);
      out.pop_back();
    }
  }
};


// Iterative
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    vector<vector<int>> curr(1);
    // index points to the position of the current number in curr.
    unordered_map<int, int> index;
    for (int i = 0; i < nums.size(); ++i) {
      int n = curr.size();
      int start = index[nums[i]];
      index[nums[i]] = n;
      for (int j = start; j < n; ++j) {
        if (!curr[j].empty() && curr[j].back() > nums[i]) {
          continue;
        }
        curr.push_back(curr[j]);
        curr.back().push_back(nums[i]);
        if (curr.back().size() >= 2) {
          result.push_back(curr.back());
        }
      }
    }
    return result;
  }
};
