class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int nums_len = nums.size();
      if (nums_len == 0) {
        return 0;	      
      }
      int min_len = INT_MAX;
      int sum = 0;
      int left = 0;
      int right = 0;
      while (right < nums_len) {
        while (sum < s && right < num_len) {
          right += 1;
	  sum += nums[right];
	}
	if (sum >= s) {
          min_len = min(min_len, right - left + 1);
	  sum -= nums[left];
	  left += 1;
	}
      }
      return min_len > len ? 0 : min_len;
    }
};
