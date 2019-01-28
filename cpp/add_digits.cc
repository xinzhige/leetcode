// Time: O(logn)
class Solution {
public:
  int addDigits(int num) {
    while (num > 9) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      num = sum;
    }
    return num;
  }
};


// Time: O(1)
class Solution {
public:
  int addDigits(int num) {
    return 1 + (num - 1) % 9;
  }
};
