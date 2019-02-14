class Solution {
public:
  int countDigitOne(int n) {
    long ones = 0;
    for (long m = 1; m <= n; m *= 10) {
      long a = n / m;
      long b = n % m;
      long c = long((a % 10) == 1) * (b + 1);
      // if current digit is 0 or 1 then no carry
      ones += (a + 8) / 10 * m + c;
    }
    return int(ones);
  }
};
