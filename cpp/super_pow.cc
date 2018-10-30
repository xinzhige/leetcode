class Solution {
public:
  int superPow(int a, vector<int>& b) {
    int p = 0;
    for (const auto &i : b) {
      p = (p * 10 + i) % 1140;
    }
    if (p == 0) {
      p += 1140;
    }
    return power(a, p, 1337);
  }
  int power(int x, int n, int mod) {
    int result = 1;
    x %= mod;
    for (; n > 0; n >>= 1) {
      if ((n & 1) == 1) {
        result = (result * x) % mod;
      }
      x = x * x % mod;
    }
    return result;
  }
};
