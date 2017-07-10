class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    map<long long, int> m;
    for (int j = 0, i = 0; i < nums.size(); ++i) {
      if (i - j > k) {
        m.erase(nums[j]);
        j += 1;
      }
      auto p = m.lower_bound((long long)nums[i] - t);
      if (p != m.end() && (p->first - nums[i]) <= t) {
        return true;
      }
      m[nums[i]] = i;
    }
    return false;
  }
};
