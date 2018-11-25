// Idea: DP, for each position i, calculate minimum swaps so far including
// 1) swap at i and 2) no swap at i.
// Trick: there is only two cases that guarantee the two array sorted.
class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    vector<int> prev = {0, 1};
    vector<int> curr(2, 0);
    for (int i = 1; i < A.size(); ++i) {
      curr[0] = INT_MAX;
      curr[1] = INT_MAX;
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        curr[0] = min(curr[0], prev[0]);
        curr[1] = min(curr[1], prev[1] + 1);
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        curr[0] = min(curr[0], prev[1]);
        curr[1] = min(curr[1], prev[0] + 1);
      }
      prev = curr;
    }
    return min(prev[0], prev[1]);
  }
};
