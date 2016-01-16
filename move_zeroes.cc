class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int pos = 0; // points to the first zero
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] != 0) {
        swap(nums[pos], nums[i]);
        pos += 1;
      }
    }
  }
};
