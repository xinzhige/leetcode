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


// Linked list cycle 2 like algorithm
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

