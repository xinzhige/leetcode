class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = n - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) / 2);
            if (A[mid] == target) {
                return true;    
            }
            if (A[left] < A[mid]) {   //left half is sorted
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]) { //right half is sorted
                if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left += 1; // we dont know what the situation is on the left part, for example, one is {3, 3, 3, 3, 0, 1, 2} or {3, 4, 5, 6, 3, 3, 3, 3, 3}
            }
        }
        return false;
    }
};
