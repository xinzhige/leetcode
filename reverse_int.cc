class Solution {
public:
  int reverse(int x) {
    int result = 0;
    int sign = 1;
    if (x < 0) {
      x = (-1) * x;
      sign = -1;
    }
    for (; x > 0; x = x/10) {
      result = result*10 + x%10;
    }
    if(result < 0) { // determine if the result overflows
      return INT_MIN;
    }
    return sign * result; 
  }
};
