class Solution {
public:
  int integerReplacement(int n) {
    if (n == 1) {
      return 0;
    }
    if ((n % 2) == 0) {
      return 1 + integerReplacement(n / 2);
    } else {
      long long t = n;
      return 2 + min(integerReplacement((t + 1) / 2),
                     integerReplacement((t - 1) / 2));
    }
  }
};


// Iterative
class Solution {
public:
  int integerReplacement(int n) {
    long long t = n;
    int count = 0;
    while (t > 1) {
      if ((t & 1) == 0) {
        t >>= 1;
      } else if (t == 3 || ((t >> 1) & 1) == 0) {
        --t;
      } else {
        ++t;
      }
      ++count;
    }
    return count;
  }
};
