// Time: O(nloglogn), space: O(n)
class Solution {
public:
  int countPrimes(int n) {
    if (n < 3) {
      return 0;
    }
    vector<bool> prime(n, true);
    int count = 0;
    for (int i = 2; i < sqrt(n); ++i) {
      if (prime[i]) {
        for (int j = i * i; j < n; j += i) {
          if (prime[j]) {
            prime[j] = false;
            count += 1;
          }
        }
      }
    }
    return n - 2 - count;
  }
};
