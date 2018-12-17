class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x = 1 / x
            n = abs(n)
        result = 1
        while n > 0:
            if (n & 1) > 0:
                result *= x
            x *= x
            n >>= 1
        return result
