class Solution {  
public:  
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        size_t nums_len = nums.size();
        for (int i = 0; i < nums_len; i++) {
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }
            int l = i + 1;
            int r = nums_len - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp > 0) {
                    r -= 1;
                } else if (tmp < 0) {
                    l += 1;
                } else {
                    result.emplace_back(vector<int> {nums[i], nums[l], nums[r]});
                    for (; nums[l] == nums[l + 1]; ++l); 
                    for (; nums[r] == nums[r - 1]; --r); 
                    l += 1; 
                    r -= 1;
                }
            }
        }
        return result;
    }
};
