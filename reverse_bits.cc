class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
      uint32_t curr_digit = n & 1;
      if (result <= UINT32_MAX / 2 && 2 * result <= UINT32_MAX - curr_digit) {
	result = result * 2 + curr_digit;
        n >>= 1;
      } else {
        return UINT32_MAX;	      
      }
    }
    return result;
  }
};
