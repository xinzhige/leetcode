class Solution {
public:
    int arrangeCoins(int n) {
        long low = 1;
        long high = n;
        while (low < high) {
            long mid = low + (high - low) / 2 + 1;
            if ((mid + 1) * mid / 2.0 <= n) {
                low = mid;
            } else {
                high = mid - 1;
            }
        } 
        return high;
    }
};


// Use mathematical formula
class Solution {
public:
    int arrangeCoins(int n) {
         return (int) ((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};
