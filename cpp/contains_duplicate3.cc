// Idea: two pointers to control the range and map to find lower bound.
// Note: long long to handle INT_MIN.
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    map<long long, int> index;
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      // make sure the range is not greater than k
      if (i - j > k) {
        index.erase(nums[j]);
        j += 1;
      }
      // x >= nums[i] - t
      auto p = index.lower_bound((long long)nums[i] - t);
      // x <= nums[i] + t
      if (p != index.end() && (p->first - nums[i]) <= t) {
        return true;
      }
      index[nums[i]] = i;
    }
    return false;
  }
};
