class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        y = x
        while y * y > x:
            y = (y + x // y) // 2
        return y
