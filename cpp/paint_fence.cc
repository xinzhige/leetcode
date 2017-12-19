class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0) {
      return 0;
    }
    // Varible same means how many ways so far are there if post i is the
    // same color as post i-1. Varible diff means how many ways are there
    // if post i is different from post i-1.
    int same = 0;
    int diff = k;
    for (int i = 2; i <= n; ++i) {
      int temp = diff;
      diff = (same + diff) * (k - 1);
      same = temp;
    }
    return same + diff;
  }
};
