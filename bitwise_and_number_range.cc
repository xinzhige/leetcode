class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int len = 0;
    for (; m != n; m >>= 1, n >>= 1) {
      len += 1;
    }
    int result = (m << len);
    return result;
  }
};
