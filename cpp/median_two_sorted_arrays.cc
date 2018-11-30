// Idea: split the two arrays into four parts [..., i-1 | i,...] and
// [..., j-1 | j, ...] such that they have the following two properties:
// 1: i + j = (m + n + 1) / 2;
// 2: nums1[i-1] < nums2[j] and nums[j-1] < nums1[i].
// Then, use binary search to find i between imin and imax until it satisfies
// the previous properties.
// Note that m must be less than or equal to n, otherwise j might be overflow.
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int imin = 0;
    int imax = m;
    int half_len = (m + n + 1) / 2;
    int i = 0;
    int j = 0;
    int left_max = 0;
    int right_min = 0;
    while (imin <= imax) {
      i = (imin + imax) / 2;
      j = half_len - i;
      if (i < m && nums2[j-1] > nums1[i]) {
        imin = i + 1;
      } else if (i > 0 && nums1[i-1] > nums2[j]) {
        imax = i - 1;
      } else {
        if (i == 0) {
          left_max = nums2[j-1];
        } else if (j == 0) {
          left_max = nums1[i-1];
        } else {
          left_max = max(nums1[i-1], nums2[j-1]);
        }
        if ((m + n) % 2 == 1) {
          return left_max;
        }
        if (i == m) {
          right_min = nums2[j];
        } else if (j == n) {
          right_min = nums1[i];
        } else {
          right_min = min(nums1[i], nums2[j]);
        }
        break;
      }
    }
    return (left_max + right_min) / 2.0;
  }
};
