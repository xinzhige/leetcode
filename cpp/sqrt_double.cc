class Solution {
public:
  double mySqrt(double x, double e) {
    double y = 1.0;
    doulbe n = x;
    while (n - y > e) {
      n = n / 2 + y / 2;
      y = x / n;
    }
    return n;
  }
};
