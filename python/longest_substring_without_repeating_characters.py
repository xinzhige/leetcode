class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_len = 0
        result = ""
        for i in range(len(s)):
            tmp = self.expand(s, i, i)
            if len(tmp) > len(result):
                result = tmp
            tmp = self.expand(s, i, i+1)
            if len(tmp) > len(result):
                result = tmp
        return result

    def expand(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r];
