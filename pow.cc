class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        unsigned int m = (n > 0 ? n : -n);
        while (m > 0) {
            if (m & 1) {
                result *= x; 
            } 
            x *= x;
            m >>= 1;
        }
        return n < 0 ? 1.0 / result : result;
    }
};
