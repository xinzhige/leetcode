class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0; 
        }
        if (n == 3) {
            return 1; 
        }
        vector<bool> is_prime(n, true); 
        int count = 0;
        for (int i = 2; i <= (n - 1) / i; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n - 1; j += i) {
                    if (is_prime[j]) {
                        is_prime = false;
                        count += 1;
                    } 
                } 
            } 
        }
        return n-2-count;
    }
};
