// Binary search
class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      int count = 0;
      for (auto &i : nums) {
        if (i <= mid) {
          count++;
        }
      }
      if (count <= mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};


// Idea: like finding the starting point of cycle linked list problem.
// Trick 1: each element can be value and index so the duplicates point total
// the same number that is the starting point.
// Trick 2: 0 is not in the array but can be used as the first pointer.
class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) {
        break;
      }
    }
    fast = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[fast];
      if (slow == fast) {
        break;
      }
    }
    return slow;
  }
};

