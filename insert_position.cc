class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int begin = 0;
    int end = n - 1;
    int middle;
    while (begin < end) {
      middle = (begin + end)/2;
      if (A[middle] < target) {
	begin += 1;
      } else {
	end = middle;
      }
    }
    return A[begin] >= target ? begin : begin+1;
  }
};
