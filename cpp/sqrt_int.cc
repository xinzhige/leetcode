// Idea: Newton's method, let f(x) = X^2 - N,
// then f(Xn+1) - f(Xn) = f'(Xn)(Xn+1 - Xn) ==> Xn+1 = (Xn + N / Xn) / 2
// Trick 1: use y = n + (y - n) / 2 instead of y = (y + n) / 2 because then
// latter one might be overflow.
// Trick 2: the first guess must be y = x, otherwise y would be larger than
// n after the first iteration. For example, x = 8, y = 1, n = 8, then
// y = (y + n) / 2 = (1 + 8) / 2 = 4 > n = x / y = 8 / 4 = 2.
class Solution {
public:
  int mySqrt(int x) {
    int y = x;
    int n = 1;
    while (y > n) {
      y = n + (y - n) / 2;
      n = x / y;
    }
    return y;
  }
};
