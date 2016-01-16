// DP, time: O(n^2), space: O(n)
class Solution {
public:
  bool canJump(int A[], int n) {
    if (n <= 0) {
      return false;
    }
    vector<bool> check(n, false);
    if (A[0] >= 0) {
      check[0] = true;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = i-1; j >= 0; --j) {
	if (check[j] && j+A[j] >= i) {
	  check[i] = true;
	  break;
	}
      }
    }
    return check[n-1];
  }
};

// time: O(n), space: O(1)
class Solution {
public:
  bool canJump(int A[], int n) {
    int flag = n - 1;
    for(int i = n -2; i >= 0; --i) {
      if(i+A[i] >= flag) {   //reachable from A[i] to flag
	flag = i;
      }
    }
    return flag == 0;
  }
};
