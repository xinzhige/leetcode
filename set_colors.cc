// two iterations
class Solution {
public:
  void sortColors(int A[], int n) {
    int num_zeros = 0;
    int num_ones = 0;
    int num_twos = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i] == 0) {
	++num_zeros;
      }
      if (A[i] == 1) {
	++num_ones;
      }
      if (A[i] == 2) {
	++num_twos;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i < num_zeros) {
	A[i] = 0;
      } else if (i < num_zeros+num_ones) {
	A[i] = 1;
      } else if (i < n) {
	A[i] = 2;
      }
    }
  }
};

// one iteration
class Solution {
public:
  void sortColors(int A[], int n) {
    int r = 0;  // the most right index of red
    int w = 0;  // current index
    int b = n-1; // the most left index of blue
    while (w <= b) {
      if(A[w] == 0) {
	swap(A[r++], A[w++]);  // why also w++? because r's next position can only be white 
      } else if (A[w] == 2) {
	swap(A[b--], A[w]);
      } else {
	w++;
      }
    }
  }
};
