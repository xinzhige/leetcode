class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = 0;
        for (int n = x ^ y; n > 0; n &= n - 1) {
            sum += 1;
        }                    
        return sum;
    }
};
