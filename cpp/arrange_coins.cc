class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (0.5 * mid * (mid + 1) <= n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 
        return low - 1;
    }
};


// Use mathematical formula
class Solution {
public:
    int arrangeCoins(int n) {
         return (int) ((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};
