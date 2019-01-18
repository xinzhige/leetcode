// Idea: use hashmap to store the cumulative sum (modulo) to index.
// If there are two indices i and j such abs(i-j) > 1 and sum[i] = sum[j].
// Note: index[0] = -1 in case nums{0, 0} and k = 0.
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> index;
    index[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int tmp = (k == 0) ? sum : (sum % k);
      if (index.count(tmp) > 0) {
        if (i - index[tmp] > 1) {
          return true;
        }
      } else {
        index[tmp] = i;
      }
    }
    return false;
  }
};
