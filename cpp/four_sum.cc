class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    set<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
      for (int j = i + 1; j < n - 2; ++j) {
        if (j == i + 1 || nums[j] != nums[j-1]) {
          int l = j + 1;
          int r = n - 1;
          while (l < r) {
            int sum = nums[i] + nums[j] + nums[l] + nums[r];
            if (sum < target) {
              ++l;
            } else if (sum > target) {
              --r;
            } else {
              result.insert({nums[i], nums[j], nums[l], nums[r]});
              ++l;
              --r;
            }
          }
        }
      }
    }
    return vector<vector<int>> (result.begin(), result.end());
  }
};
