class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sum;
        int curr_sum = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i]; 
            if (curr_sum == k) {
                max_len = i + 1; 
            } else if (sum.find(curr_sum - k) != sum.end()) {
                max_len = max(max_len, i  - sum[curr_sum - k]); 
            }
            if (sum.find(curr_sum) == sum.end()) {
                sum[curr_sum] = i; 
            }
        }
        return max_len;
    }
};
