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


// Quick sort like, time: O(n), space: O(1).
// Note: the left part is larger than the right part after partition.
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size() - 1;
    int p = 0;
    while (low <= high) {
      p = partition(nums, low, high);
      if (p == k - 1) {
        break;
      } else if (p < k - 1) {
        low = p + 1;
      } else {
        high = p - 1;
      }
    }
    return nums[p];
  }
  int partition(vector<int>& nums, int low, int high) {
    int l = low + 1;
    int h = high;
    int pivot = nums[low];
    while (l <= h) {
      if (nums[l] < pivot && pivot < nums[h]) {
        swap(nums[l++], nums[h--]);
      }
      if (nums[l] >= pivot) {
        ++l;
      }
      if (nums[h] <= pivot) {
        --h;
      }
    }
    swap(nums[low], nums[h]);
    return h;
  }
};
