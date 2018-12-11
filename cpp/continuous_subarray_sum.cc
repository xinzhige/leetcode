class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    map<int, int> index;
    index[0] = -1;
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
