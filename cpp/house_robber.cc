class Solution {
public:
  int rob(vector<int>& nums) {
    int prev_max = 0;
    int curr_max = 0;
    for (auto &n : nums) {
      int curr = max(curr_max, prev_max + n);
      prev_max = curr_max;
      curr_max = curr;
    }
    return curr_max;
  }
};
