class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        m = len(nums1)
        n = len(nums2)
        imin = 0
        imax = m
        i = 0
        j = 0
        half_len = (m + n + 1) // 2
        left_max = 0
        right_min = 0
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i > 0 and nums1[i-1] > nums2[j]:
                imax = i - 1
            elif i < m and nums2[j-1] > nums1[i]:
                imin = i + 1
            else:
                if i == 0:
                    left_max = nums2[j-1]
                elif j == 0:
                    left_max = nums1[i-1]
                else:
                    left_max = max(nums1[i-1], nums2[j-1])
                if (m + n) % 2 == 1:
                    return left_max
                if i == m:
                    right_min = nums2[j]
                elif j == n:
                    right_min = nums1[i]
                else:
                    right_min = min(nums1[i], nums2[j])
                break
        return (left_max + right_min) / 2.0
