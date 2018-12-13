// Idea: 1. calculate how many digits the number has.
// 2. calculate what the number is.
// 3. find out which digit in the number is we wanted.
class Solution {
public:
  int findNthDigit(int n) {
    long long len = 1;
    long long count = 9;
    long long start = 1;
    while (n / len > count) {
      n -= len * count;
      ++len;
      count *= 10;
      start *= 10;
    }
    start += (n - 1) / len;
    string t = to_string(start);
    return t[(n - 1) % len] - '0';
  }
};
