class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    // left and right are initialized such that right-start+1=0
    int left = 1;
    int right = 0;
    int currMin = nums[n-1];
    int currMax = nums[0];
   for (int i = 1; i < n; ++i) {
     currMax = max(currMax, nums[i]);
     currMin = min(currMin, nums[n-1-i]);
     if (nums[i] < currMax) {
       right = i;
     }
     if (nums[n-1-i] > currMin) {
       left = n - 1 - i;
     }
   }
   return right - left + 1;
 }
};
