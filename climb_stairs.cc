// this problem can be transformed into the Fibonacci problem because f(n) = f(n-1) + f(n-2)
class Solution {
public:
  int climbStairs(int n) {
    int first = 0;
    int second = 1;
    int sum = 1;
    for (int i = 1; i <= n; ++i) {
      sum  = first + second;
      first = second;
      second = sum;
    }
    return sum;
  }
};
