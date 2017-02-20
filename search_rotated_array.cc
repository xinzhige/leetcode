class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (A[mid] == target) {
                return mid;
            }
            if (A[left] <= A[mid]) {  // left side is sorted
                if (A[left] <= target && target < A[mid]) {  // to decide if target is in between left and mid, for example, 4 5 6 7 0 1 2, left=0, mid=3, target=1, where 1 is not in between left and mid and A[left] <= target is needed.
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {  
                if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
