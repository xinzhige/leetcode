class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int result = 0;
    int num = 0;
    for (int i = 2; i < A.size(); ++i) {
      if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
        num += 1;
        result += num;
      } else {
        num = 0;
      }
    }
    return result;
  }
};
