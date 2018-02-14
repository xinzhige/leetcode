class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    // The first loop is to compute the multiplication of previous numbers.
    for (int i = 1; i < n; ++i) {
      result[i] = result[i-1] * nums[i-1];
    }
    int fac = 1;
    // The second loop is to compute the multiplication of post numbers
    // and the result. Note that i starts with n - 2 because the last element
    // of result has been already the final value.
    for (int i = n - 2; i >= 0; --i) {
      fac *= nums[i+1];
      result[i] *= fac;
    }
    return result;
  }
};
