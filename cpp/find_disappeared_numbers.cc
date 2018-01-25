class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index]; 
            }
        }
        vector<int> disappeared_numbers;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                disappeared_numbers.push_back(i + 1);
            } 
        }
        return disappeared_numbers;
    }
};
