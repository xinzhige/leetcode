class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        int mid = 0;
        // Find min left s.t. nums[left] < nums[left + 1]. 
        while (left < right && nums[left] > nums[right]) {
            mid = left + ((right - left) / 2);
            if (nums[mid] < nums[left]) {
                right = mid;  
            } else {
                left = mid + 1; 
            }
        }
        return nums[left];
    }
};
