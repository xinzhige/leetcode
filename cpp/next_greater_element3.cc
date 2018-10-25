class Solution {
public:
  int nextGreaterElement(int n) {
    string str = to_string(n);
    int len = str.size();
    int i = len - 1;
    for (; i > 0 && str[i] <= str[i - 1]; --i);
    if (i == 0) {
      return -1;
    }
    for (int j = len - 1; j >= i; --j) {
      if (str[j] > str[i - 1]) {
        swap(str[j], str[i - 1]);
        break;
      }
    }
    sort(str.begin() + i, str.end());
    long long result = stoll(str);
    return result > INT_MAX ? -1 : result;
  }
};
