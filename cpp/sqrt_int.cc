class Solution {
public:
  int mySqrt(int x) {
    int y = 1;
    int n = x;
    while (n > y) {
      if (n % 2 && y % 2) {
        n = n / 2 + y / 2 + 1;
      } else {
        n = n / 2 + y / 2;
      }
      y = x / n;
    }
    return n;
  }
};
