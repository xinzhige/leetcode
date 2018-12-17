# Idea: decide which half is sorted.
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        begin = 0
        end = len(nums) - 1
        while begin <= end:
            mid = (begin + end) // 2
            if nums[mid] == target:
                return mid
            elif nums[begin] <= nums[mid]:
                if nums[begin] <= target and target < nums[mid]:
                    end = mid - 1
                else:
                    begin = mid + 1
            else:
                if nums[mid] < target and target <= nums[end]:
                    begin = mid + 1
                else:
                    end = mid - 1

        return -1
