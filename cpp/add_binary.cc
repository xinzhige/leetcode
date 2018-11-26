class Solution {
public:
  string addBinary(string a, string b) {
    string result("");
    long carry = 0;
    long i = a.size() - 1;
    long j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry == 1) {
      int x = (i >= 0 ? a[i] - '0' : 0);
      int y = (j >= 0 ? b[j] - '0' : 0);
      int sum = x + y + carry;
      result.insert(result.begin(), '0' + (sum % 2));
      carry = sum / 2;
      --i;
      --j;
    }
    return result;
  }
};
