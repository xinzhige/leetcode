class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int head = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != nums[head]) {
	nums[head + 1] = nums[i];
	head += 1;
      }
    }
    return head + 1;
  }
};
