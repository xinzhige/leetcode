class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    long len1 = num1.size(), len2 = num2.size();
    long len3 = len1 + len2;
    long i, j , product, carry;
    vector<long> num3(len3, 0);
    for (i = len1 - 1; i >= 0; --i) {
      carry = 0;
      for (j = len2 - 1; j >= 0; --j) {
	product = carry + num3[i+j+1] + (num1[i] - '0') * (num2[j] - '0');
	num3[i+j+1] = product % 10;
	carry = product / 10;
      }
      num3[i+j+1] = carry;
    }
    string result("");
    i = 0;
    while (i < len3 - 1 && num3[i] == 0)
      ++i;
    while (i < len3)
      result.push_back(num3[i++] + '0');
    return result;
  }
};
