class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    int result = n;
    int remainder = 0;
    while (result > 1) {
      remainder = result % 2;
      result /= 2;
      if (remainder == 1) {
        return false;
      }
    }
    return result == 1;
  }
};

// bit operation
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return n<=0 ? false : (n & (n-1)) == 0; 
  }
};
