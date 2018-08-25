// Time: O(n), space: O(n)
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    int m = (n + 1) / 2;
    vector<int> copy(nums);
    nth_element(nums.begin(), nums.begin() + m, nums.end());
    int median = nums[m];
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
      if (copy[j] < median) {
        swap(copy[i], copy[j]);
        ++i;
        ++j;
      } else if (copy[j] > median) {
        swap(copy[j], copy[k]);
        --k;
      } else {
        ++j;
      }
    }
    for (int i = 0, j = m - 1; j >= 0; i += 2, --j) {
      nums[i] = copy[j];
    }
    for (int i = 1, j = n - 1; j >= m; i += 2, --j) {
      nums[i] = copy[j];
    }
  }
};


// Time: O(n), space: O(1)
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    #define A(i) nums[(1+2*(i)) % (n|1)]
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
      if (A(j) > mid) {
        swap(A(i++), A(j++));
      } else if (A(j) < mid) {
        swap(A(j), A(k--));
      } else {
        j++;
      }
    }
  }
};
