class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    int result = 10;
    int count = 9;
    for (int i = 2; i <= n; ++i) {
      count *= 11 - i;
      result += count;
    }
    return result;
  }
};
