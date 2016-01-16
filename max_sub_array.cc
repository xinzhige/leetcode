class Solution {
public:
  int maxSubArray(int A[], int n) {
    int max_so_far = A[0];
    int max_ending_here = A[0];
    // int begin = 0;
    // int begin_temp = 0;
    // int end = 0;
    for (int i = 1; i < n; ++i) {
      if (max_ending_here < 0) {
	max_ending_here = A[i];
	// begin_temp = i;
      } else {
	max_ending_here += A[i];
      }
      if (max_ending_here > max_so_far) {
	max_so_far = max_ending_here;
	// begin = begin_temp;
	// end = i;
      }
    }
    return max_so_far;
  }
};
