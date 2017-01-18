class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        bool has_min = false;
        bool has_max = false;
        if (nums.size() > 0) {
            if (nums.front() == INT_MIN) has_min = true;
            if (nums.back() == INT_MAX) has_max = true;
        }
        if (upper == INT_MAX) {
            nums.push_back(upper); 
        } else {
            nums.push_back(upper + 1);
        }
        int pre = (lower == INT_MIN) ? lower : lower - 1;
        for (auto i : nums) {
            if (i == INT_MAX && !has_max) {
                if (pre == INT_MIN && !has_min) {
                    result.push_back(std::to_string(pre) + "->" + 
                                     std::to_string(i));
                } else {
                    result.push_back(std::to_string(pre + 1) + "->" + 
                                     std::to_string(i));
                }
                break;
            } else if (pre == INT_MIN && !has_min) {
                result.push_back(std::to_string(pre) + "->" + 
                                 std::to_string(i - 1));
            } else if ((i >= 0 && pre < 0 && i > INT_MAX + pre) ||
                       (i - pre > 2)) {
                result.push_back(std::to_string(pre + 1) + "->" + 
                                 std::to_string(i - 1)); 
            } else if (i - pre == 2) {
                result.push_back(std::to_string(i - 1)); 
            }
            pre = i;
        }
        return result;
    }
};
