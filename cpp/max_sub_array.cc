class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_ending_here = nums[0];
        // int begin = 0;
        // int begin_temp = 0;
        // int end = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (max_ending_here < 0) {
                max_ending_here = nums[i];
                // begin_temp = i;
            } else {
                max_ending_here += nums[i];
            }
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
                // begin = begin_temp;
                // end = i;
            }
        }
        return max_so_far;
    }
};
