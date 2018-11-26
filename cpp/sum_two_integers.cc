// First, we can use "and"("&") operation between a and b to find a carry.
// carry = a & b, then carry = 0001;
// Second, we can use "xor" ("^") operation between a and b to find
// the different bit, and assign it to a;
// Then, we shift carry one position left and assign it to b, b = 0010.
class Solution {
public:
  int getSum(int a, int b) {
    while (b != 0) {
      int carry = a & b;
      a ^= b;
      b = carry << 1;
    }
    return a;
  }
};
