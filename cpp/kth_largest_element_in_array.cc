// Priority queue, time: O(nlgk), space: O(k)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int &x : nums) {
      pq.push(x);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};


// Quick sort like, time: O(n), space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int pos = 0;
    while (left < right) {
      pos = partition(nums, left, right);
      if (pos == k - 1) {
        break;
      } else if (pos < k - 1) {
        left = pos + 1;
      } else {
        right = pos - 1;
      }
    }
    return nums[pos];
  }
  int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1;
    int r = right;
    while (l <= r) {
      if (nums[l] < pivot && pivot < nums[r]) {
        swap(nums[l], nums[r]);
        ++l;
        --r;
      }
      if (nums[l] >= pivot) {
        ++l;
      }
      if (nums[r] <= pivot) {
        --r;
      }
    }
    swap(nums[left], nums[r]);
    return r;
  }
};
