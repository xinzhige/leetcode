// DFS
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }
    vector<int> groups(k, 0);
    int target = sum / k;
    int row = nums.size() - 1;
    sort(nums.begin(), nums.end());
    return search(nums, target, groups, row);
  }
  bool search(vector<int>& nums, int target, vector<int>& groups, int row) {
    if (row < 0) {
      for (auto t : groups) {
        if (t != target) {
          return false;
        }
      }
      return true;
    }
    int num = nums[row];
    for (int i = 0; i < groups.size(); ++i) {
      if (groups[i] + num <= target) {
        groups[i] += num;
        if (search(nums, target, groups, row - 1)) {
          return true;
        }
        groups[i] -= num;
      }
    }
    return false;
  }
};

// DP
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum / k;
    if (sum % k != 0 || nums[n-1] > target) {
      return false;
    }
    vector<bool> dp(1<<n, false);
    dp[0] = true;
    vector<int> total(1<<n, 0);
    for (int state = 0; state < (1<<n); ++state) {
      if (!dp[state]) {
        continue;
      }
      for (int i = 0; i < n; ++i) {
        int future = (state | (1<<i));
        if ((state != future) && (!dp[future])) {
          if (nums[i] <= target - (total[state] % target)) {
            dp[future] = true;
            total[future] = total[state] + nums[i];
          } else {
            break;
          }
        }
      }
    }
    return dp[(1<<n) - 1];
  }
};
