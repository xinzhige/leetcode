class Solution {
public:
  double pow(double x, int n) {
    bool is_negative = false;
    if (n < 0) {
      is_negative = true;
      n = abs(n);
    }
    double result = 1;
    while (n > 0) {
      if (n & 1 != 0) {
	result *= x;
      }
      n >>= 1;
      x *= x;
    }
    return is_negative ? 1.0 / result : result;
  }
};
