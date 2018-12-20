// Idea: DP, use two arrays, one is for the longest length of increasing
// subsequence ending at i; the other one is for number of that subsequences.
// Time: O(n^2)
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int result = 0;
    int curr_max = 0;
    int n = nums.size();
    vector<int> len(n, 1);
    vector<int> count(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (len[i] == len[j] + 1) {
            count[i] += count[j];
          } else if (len[i] < len[j] + 1) {
            len[i] = len[j] + 1;
            count[i] = count[j];
          }
        }
      }
      if (curr_max == len[i]) {
        result += count[i];
      } else if (curr_max < len[i]) {
        curr_max = len[i];
        result = count[i];
      }
    }
    return result;
  }
};


// Idea: DP + binary search
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<vector<pair<int, int>>> dyn(nums.size() + 1);
    int curr_max = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int l = 0;
      int r = curr_max;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (dyn[mid].back().first < nums[i]) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      int options = 1;
      int row = l - 1;
      if (row >= 0) {
        int l1 = 0;
        int r1 = dyn[row].size() - 1;
        while (l1 < r1) {
          int mid = l1 + (r1 - l1) / 2;
          if (dyn[row][mid].first < nums[i]) {
            r1 = mid;
          } else {
            l1 = mid + 1;
          }
        }
        options = dyn[row].back().second;
        if (l1 != 0) {
          options -= dyn[row][l1 - 1].second;
        }
      }
      if (dyn[l].empty()) {
        dyn[l].push_back({nums[i], options});
      } else {
        dyn[l].push_back({nums[i], dyn[l].back().second + options});
      }
      if (l == curr_max) {
        curr_max += 1;
      }
    }
    return dyn[curr_max-1].back().second;
  }
};
