// Four passes
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int currMin = INT_MAX;
    int currMax = INT_MIN;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1])
        currMin = min(currMin, nums[i]);
    }
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        currMax = max(currMax, nums[i]);
    }
    int l = 0;
    int r = nums.size() - 1;
    for (; l < nums.size(); l++) {
      if (currMin < nums[l])
        break;
    }
    for (; r >= 0; r--) {
      if (currMax > nums[r])
        break;
    }
    if (r - l < 0) {
      return 0;
    } else {
      return r - l + 1;
    }
  }
};


// One pass
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    // begin and end are initialized such that end-start+1=0
    int begin = 1;
    int end = 0;
    int currMin = nums[n-1];
    int currMax = nums[0];
   for (int i = 1; i < n; ++i) {
     currMax = max(currMax, nums[i]);
     currMin = min(currMin, nums[n-1-i]);
     if (nums[i] < currMax) {
       end = i;
     }
     if (nums[n-1-i] > currMin) {
       begin = n - 1 - i;
     }
   }
   return end - begin + 1;
 }
};
