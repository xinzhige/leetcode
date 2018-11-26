// Trick: if the carry is 0, then it is not necessary to calculate the sum.
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result;
    int carry = 1;
    for (long i = digits.size() - 1; i >= 0 || carry == 1; --i) {
      if (carry == 1) {
        int sum = (i >= 0 ? digits[i] + carry : carry);
        result.insert(result.begin(), sum % 10);
        carry = sum / 10;
      } else {
        result.insert(result.begin(), digits[i]);
      }
    }
    return result;
  }
};
