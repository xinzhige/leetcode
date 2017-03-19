class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int end = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[end]) {
	nums[end + 1] = nums[i];
	end += 1;
      }
    }
    return end + 1;
  }
};
