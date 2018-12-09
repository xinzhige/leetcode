// Idea: find median and reset the index to the right place.
// Note: if there are even numbers, n | 1.
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
      if (nums[A(j, n)] > mid) {
        swap(nums[A(i++, n)], nums[A(j++, n)]);
      } else if (nums[A(j, n)] < mid) {
        swap(nums[A(j, n)], nums[A(k--, n)]);
      } else {
        j++;
      }
    }
  }
  int A(int i, int n) {
    return (1 + 2 * (i)) % (n | 1);
  }
};


class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    int median = findKthLargest(nums, (n + 1) / 2);
    int left = 0;
    int i = 0;
    int right = n - 1;
    while (i <= right) {
      if (nums[newIndex(i, n)] > median) {
        swap(nums[newIndex(left++, n)], nums[newIndex(i++, n)]);
      } else if (nums[newIndex(i, n)] < median) {
        swap(nums[newIndex(right--, n)], nums[newIndex(i, n)]);
      } else {
        ++i;
      }
    }
  }
  int findKthLargest(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    int pos = 0;
    while (true) {
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
  int newIndex(int index, int n) {
    return (1 + 2 * index) % (n | 1);
  }
};
