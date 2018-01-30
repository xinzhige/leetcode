class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<bool> used(num.size(), false);
    vector<int> path;
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    permuteHelper(num, used, path, result);
    return result;
  }
private:
  void permuteHelper(vector<int> &num, vector<bool> &used, vector<int> &path, vector<vector<int> > &result) {
    if (num.size() == path.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < num.size(); ++i) {
      if (!used[i]) {
        if (i != 0 && num[i] == num[i-1] && used[i-1]) {
          continue;
        }
        used[i] = true;
        path.push_back(num[i]);
        permuteHelper(num, used, path, result);
        used[i] = false;
        path.pop_back();
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
