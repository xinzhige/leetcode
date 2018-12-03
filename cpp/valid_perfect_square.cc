class Solution {
public:
  bool isPerfectSquare(int num) {
    int x = num;
    int n = 1;
    while (x > n) {
      x = n + (x - n) / 2;
      n = num / x;
    }
    return x * x == num;
  }
};
