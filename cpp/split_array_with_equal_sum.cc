class Solution {
public:
  bool splitArray(vector<int>& nums) {
    int n = nums.size();
    if (n < 7) {
      return false;
    }
    vector<int> sum(n, 0);
    sum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + nums[i];
    }
    for (int j = 3; j < n - 3; ++j) {
      unordered_set<int> myset;
      for (int i = 1; i < j - 1; ++i) {
        if (sum[i - 1] == sum[j - 1] - sum[i]) {
          myset.insert(sum[i - 1]);
        }
      }
      for ( int k = j + 2; k < n - 1; ++k) {
        if (sum[n - 1] - sum[k] == sum[k - 1] - sum[j] &&
            myset.count(sum[k - 1] - sum[j]) > 0) {
          return true;
        }
      }
    }
    return false;
  }
};


class Solution {
public:
  bool splitArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n, 0);
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + nums[i];
    }
    for (int i = 1; i < n - 4; ++i) {
      if (i != 1 && nums[i] == 0 && nums[i - 1] == 0) continue;
      for (int j = i + 2; j < n - 2; ++j) {
        if (sums[i - 1] == (sums[j - 1] - sums[i])) {
          for (int k = j + 2; k < n; ++k) {
            int sum3 = sums[k - 1] - sums[j];
            int sum4 = sums[n - 1] - sums[k];
            if (sum3 == sum4 && sum3 == sums[i - 1]) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }
};
