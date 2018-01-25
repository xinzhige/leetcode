// If k << n, then use selection sort.
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
	if (nums[i] < nums[j]) {
	  swap(nums[i], nums[j]);
	}
      }
    }
    return nums[k-1];
  }
};

// If k is large, then use heap sort.
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nums.size(); ++i) {
      q.emplace(nums[i]);
      if (q.size() > k) {
	q.pop();
      }
    }
    return q.top();
  }
};
