// consider each bar, for current bar, the amount of water trapped: min(left_highest,right_highest)-i
class Solution {
public:
  int trap(int A[], int n) {
    if (n < 2) {
      return 0;
    }    
    int l[n];
    int r[n];
    int result = 0;
    l[0] = 0;
    for (int i = 1; i < n; ++i){
      l[i] = max(l[i-1], A[i-1]);
    }
    r[n-1] = 0;
    for (int i = n-2; i >= 0; --i){
      r[i] = max(r[i+1], A[i+1]);
    }
    for (int i = 0; i < n; ++i){
      if (min(l[i],r[i]) - A[i] > 0){
	result += min(l[i],r[i])-A[i];
      }
    }
    return result;
  }
};

// time: O(n), space: O(1)
class Solution {
public:
  int trap(int A[], int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i] > A[max]) {
	max = i;
      }
    }
    int water = 0;
    for (int i = 0, peak = 0; i < max; ++i) {
      if (A[i] > peak) {
	peak = A[i];
      } else {
	water += peak - A[i];
      }
    }
    for (int i = n - 1, top = 0; i > max; --i) {
      if (A[i] > top) {
	top = A[i];
      } else {
	water += top - A[i];
      }
    }
    return water;
  }
};
