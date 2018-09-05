class Solution {
public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    vector<int> result(n, 0);
    int idx = (a >= 0 ? n - 1 : 0);
    while (i <= j) {
      int left = quad(nums[i], a, b, c);
      int right = quad(nums[j], a, b, c);
      if (a >= 0) {
        if (left >= right) {
          result[idx] = left;
          ++i;
        } else {
          result[idx] = right;
          --j;
        }
        --idx;
      } else {
        if (left >= right) {
          result[idx] = right;
          --j;
        } else {
          result[idx] = left;
          ++i;
        }
        ++idx;
      }
    }
    return result;
  }
  int quad(int x, int a, int b, int c) {
    return x * (a * x + b) + c;
  }
};
