// The result must be the product of factors (3) and the rest (4).
class Solution {
public:
  int integerBreak(int n) {
    if (n == 2 || n == 3) {
      return n - 1;
    }
    int result = 1;
    for (; n > 4; n -= 3) {
      result *= 3;
    }
    return result * n;
  }
};


// By formula
class Solution {
public:
  int integerBreak(int n) {
    if (n == 2 || n == 3) {
      return n - 1;
    }
    n -= 2;
    return pow(3, n / 3) * (n % 3 + 2);
  }
};
