class Solution {
public:
  int maximumSwap(int num) {
    vector<int> digits;
    int curr_num = num;
    for (; curr_num > 0; curr_num /= 10) {
      digits.push_back(curr_num % 10);
    }
    reverse(digits.begin(), digits.end());
    vector<int> last(10, 0);
    for (int i = 0; i < digits.size(); ++i) {
      last[digits[i]] = i;
    }
    for (int i = 0; i < digits.size(); ++i) {
      for (int d = 9; d > digits[i]; --d) {
        if (last[d] > i) {
          swap(digits[i], digits[last[d]]);
          int result = 0;
          for (const auto &d : digits) {
            result = 10 * result + d;
          }
          return result;
        }
      }
    }
    return num;
  }
};
