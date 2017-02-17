class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n == 0) {
      return 0;
    }
    int end = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i] != A[end]) {
	    A[end+1] = A[i];
	    ++end;
      }
    }
    return end+1;
  }
};
