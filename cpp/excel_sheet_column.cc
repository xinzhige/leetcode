class Solution {
public:
  string convertToTitle(int n) {
    string result;
    for (int i = n; i > 0; i /= 26) {
      i -= 1;
      result = char(i % 26 + 'A') + result;
    }
    return result;
  }
};
