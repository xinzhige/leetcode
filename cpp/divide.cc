// method 1: using '-' but time consuming
class Solution {
public:
  int divide(int dividend, int divisor) {
    assert(divisor != 0);
    if (divisor == 1 || dividend == 0) {
      return dividend;
    }
    int is_negative = (dividend^divisor)>>31;
    int count = 0;
    dividend = abs(dividend);
    divisor = abs(divisor);
    while (dividend >= divisor) {
      dividend -= divisor;
      ++count;
    }
    if (is_negative) {
      return -1 * count;
    } 
    return count;
  }
};

// method 2: using bit operation
class Solution {
public:
  int divide(int dividend, int divisor) {
    assert(divisor != 0);
    if (divisor == 1 || dividend == 0) {
      return dividend;
    }
    int is_negative = (dividend^divisor) >> 31;
    long long a = abs((long long) dividend);
    long long b = abs((long long) divisor);
    long long ret = 0;
    while (a >= b) {
      long long c = b;  // start from the base b
      for (int i = 0; a >= c; ++i, c <<= 1) {  // basically the idea is the same as the previous one except that we times c by 2 not incrementing it and if we can not substract a by c we start from b again
    	a -= c;
    	ret += 1 << i;
      }
    }
    return is_negative ? -ret : ret;
  }
};
