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
