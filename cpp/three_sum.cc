class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i == 0 || nums[i] != nums[i - 1]) {

        int l = i + 1;
        int r = n - 1;
        while (l < r) {
          int sum = nums[i] + nums[l] + nums[r];
          if (sum > 0) {
            r -= 1;
          } else if (sum < 0) {
            l += 1;
          } else {
            result.emplace_back(vector<int> {nums[i], nums[l], nums[r]});
            for (; l < n - 1 && nums[l] == nums[l + 1]; ++l);
            for (; r > 0 && nums[r] == nums[r - 1]; --r);
            l += 1;
            r -= 1;
          }
        }
      }
    }
    return result;
  }
};
