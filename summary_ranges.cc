class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> result;
        if (n == 0) {
            return result;
        }
        for (int i = 0; i < n;) {
            int start = i;
            int end = i;
            for (; end + 1 < n && nums[end + 1] == nums[end] + 1; ++end);
            if (start < end) {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            } else {
                result.push_back(to_string(nums[start]));
            }
            i = end + 1;
        }
        return result;
    }
};
