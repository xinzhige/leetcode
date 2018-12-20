// Time: O(nlogn), space: O(1)
class Solution {
public:
  int rotatedDigits(int N) {
    int result = 0;
    for (int i = 1; i <= N; ++i) {
      if (isValid(i)) {
        result += 1;
      }
    }
    return result;
  }

  bool isValid(int x) {
    int count = 0;
    for (; x > 0; x /= 10) {
      int d = x % 10;
      if (d == 3 || d == 4 || d == 7) {
        return false;
      }
      if (d == 2 || d == 5 || d == 6 || d == 9) {
        count += 1;
      }
    }
    return count > 0;
  }
};
