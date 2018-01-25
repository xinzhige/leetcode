// Binary search
class Solution {
public:
  bool judgeSquareSum(int c) {
    for (long i = 0; i * i <= c; ++i) {
      int tmp = c - (int)(i * i);
      if (binary_search(tmp, 0, tmp)) {
        return true;
      }
    }
    return false;
  }

private:
  bool binary_search(long n, long begin, long end) {
    while (begin <= end) {
      long mid = begin + (end - begin) / 2;
      if (mid * mid < n) {
        begin = mid + 1;
      } else if (mid * mid > n) {
        end = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

// Fermat's Theorem
class Solution {
public:
  bool judgeSquareSum(int c) {
    for (int i = 2; i * i <= c; ++i) {
      int count = 0;
      if (c % i == 0) {
        while (c % i == 0) {
          count++;
          c /= i;
        }
        if (i % 4 == 3 && count % 2 != 0) {
          return false;
        }
      }
    }
    return c % 4 != 3;
  }
};
