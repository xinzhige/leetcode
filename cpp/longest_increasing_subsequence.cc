// Time: O(n^2), space: O(n)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(n, 1);
    int result = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      result = max(result, dp[i]);
    }
    return result;
  }
};


// Time: O(nlgn), space: O(n)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    int len = 0;
    for (const auto &x : nums) {
      int i = binarySearch(dp, 0, len, x);
      if (i >= len) {
        dp.push_back(x);
        len += 1;
      } else {
        dp[i] = x;
      }
    }
    return len;
  }

  int binarySearch(vector<int>& nums, int begin, int end, int x) {
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] < x) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return end;
  }
};


// Use lower_bound
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> result;
    int len = 0;
    for (const auto &x : nums) {
      auto it = lower_bound(result.begin(), result.end(), x);
      if (it == result.end()) {
        result.push_back(x);
        len += 1;
      } else {
        *it = x;
      }
    }
    return len;
  }
};
