class Solution {
public:
  int compareVersion(string version1, string version2) {
    int len1 = version1.size();
    int len2 = version2.size();
    for (int i = 0, j = 0; i < len1 || j < len2; ++i, ++j) {
      int num1 = 0;
      int num2 = 0;
      for (; i < len1 && version1[i] != '.'; ++i) {
        num1 = 10 * num1 + (version1[i] - '0');
      }
      for (; j < len2 && version2[j] != '.'; ++j) {
        num2 = 10 * num2 + (version2[j] - '0');
      }
      if (num1 < num2) {
        return -1;
      } else if (num1 > num2) {
        return 1;
      }
    }
    return 0;
  }
};
