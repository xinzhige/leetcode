class Solution {
public:
  bool isPerfectSquare(int num) {
    int x = num;
    while (x > num / x) {
      x = (x + num / x) / 2;
    }
    return x * x == num;
  }
};
