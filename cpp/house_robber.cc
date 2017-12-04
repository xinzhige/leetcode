class Solution {
public:
  int rob(vector<int>& nums) {
    int prev_max = 0; 
    int curr_max = 0;
    for (int i = 0; i < nums.size(); i++) {
      int curr = max(curr_max, prev_max + nums[i]);
      prev_max = curr_max;
      curr_max = curr;
    }
    return curr_max;
  }
};
