class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_len = 0;
        for (int i = 0; i < nums.size();) {
            int j = i; 
            for (;j < nums.size() && nums[j] == 1; ++j); 
            curr_len = max(curr_len, j - i);
            i = j + 1;
        }
        return curr_len;
    }
};
