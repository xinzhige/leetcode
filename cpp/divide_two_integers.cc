// Idea: instead of multiplication, use << to shift the divisor to left.
class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
      return INT_MAX;
    }
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    int result = 0;
    while (dvd >= dvs) {
      long tmp = dvs;
      long multiple = 1;
      while (dvd >= (tmp << 1)) {
        tmp <<= 1;
        multiple <<= 1;
      }
      dvd -= tmp;
      result += multiple;
    }
    return sign == 1 ? result : -result;
  }
};
