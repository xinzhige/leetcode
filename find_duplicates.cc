class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int num_index = abs(nums[i]) - 1;
            if (nums[num_index] > 0) {
                nums[num_index] = -nums[num_index]; 
            } else {
                result.push_back(abs(nums[i])); 
            } 
        }
        return result;
    }
};
