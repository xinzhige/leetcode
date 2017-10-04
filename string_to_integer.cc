class Solution {
public:
  int atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    size_t len = str.size();
    for (; i < len && str[i] == ' '; ++i);
    if (str[i] == '-' || str[i] == '+') {
      sign = 1 - 2 * (str[i] == '-');
      ++i;
    }
    for (; i < len; ++i) {
      if (str[i] < '0' || str[i] > '9') {
        break;
      }
      int num = str[i] - '0';
      if (result > INT_MAX / 10 ||
          (result == INT_MAX / 10 && num > INT_MAX % 10)) {
        return (sign == 1 ? INT_MAX : INT_MIN);
      }
      result = 10 * result + num;
    }
    return sign * result;
  }
};
