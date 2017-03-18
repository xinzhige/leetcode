class Solution {
public:
  string convertToTitle(int n) {
    string result;
    for (; n > 0; n /= 26) {
      n -= 1;
      result += n % 26 + 'A';
    }
    return string(result.rbegin(), result.rend());
  }
};
