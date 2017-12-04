class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && i < n - 1 && A[i] == A[i-1] && A[i] == A[i+1]) {
	continue;
      } else {
	A[index] = A[i];
	++index;
      }
    }
    return index;
  }
};
