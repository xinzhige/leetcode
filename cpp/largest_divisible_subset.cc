// Idea: like longest increasing subsequence.
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n, 1);
    vector<int> pre(n, -1);
    // Note: the array should be sorted becuase the result is not ordered.
    sort(nums.begin(), nums.end());
    int cur_max = 0;
    int index = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0 && count[i] < 1 + count[j]) {
          count[i] = count[j] + 1;
          pre[i] = j;
        }
      }
      if (cur_max < count[i]) {
        cur_max = count[i];
        index = i;
      }
    }
    vector<int> result;
    while (index != -1) {
      result.push_back(nums[index]);
      index = pre[index];
    }
    return result;
  }
};
