class Solution {
public:
  void sortColors(int A[], int n) {
    int r = 0;  // the most right index of red
    int w = 0;  // current index
    int b = n-1; // the most left index of blue
    while (w <= b) {
      if(A[w] == 0) {
	swap(A[r], A[w]); 
	++r;
	++w;
      } else if (A[w] == 2) {
	swap(A[b], A[w]);
	--b;
      } else {
    	++w;
      }
    }
  }
};
