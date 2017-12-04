class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1; // Index to current character
        int j = 0; // Index to character of current repeated string 
        int n = str.size();
        /* dp stores the maximum number of characters that 
         * the string is repeating itself up to position i.
         */ 
        vector<int> dp(n + 1, 0); 
        while (i < n) {
            if (str[i] == str[j]) {
                i += 1;
                j += 1;
                dp[i] = j;
            } else if (j == 0) {
                i += 1;
            } else {
                j = dp[j];
            }
        }
        /* The last entry should be non-zero and str.size() to 
         * divide (str.size()-last entry).
         */ 
        return dp[n] && (dp[n] % (n - dp[n]) == 0);     
    }
};
