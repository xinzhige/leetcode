class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int end = m + n - 1;
    int i = m - 1;
    int j= n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[end] = nums1[i];
        i -= 1;
      } else {
        nums1[end] = nums2[j];
        j -= 1;
      }
      end -= 1;
    }
    if (i < 0) {
      while (j >= 0) {
        nums1[end] = nums2[j];
        j -= 1;
        end -= 1;
      }
    }
  }
};
