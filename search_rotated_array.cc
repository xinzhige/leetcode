// iterative
class Solution {
public:
  bool search(int A[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
      mid = left + (right - left)/2;
      if (A[mid] == target) {
	return true;     //return m in Search in Rotated Array I
      }
      if (A[left] < A[mid]) {   //left half is sorted
	if (A[left] <= target && target < A[mid]) {
	  right = mid - 1;
	} else {
	  left = mid + 1;
	}
      } else if (A[left] > A[mid]) { //right half is sorted
	if (A[mid] < target && target <= A[right]) {
	  left = mid + 1;
	} else {
	  right = mid - 1;
	}
      } else {
	++left; // we dont know what the situation is on the left part, for example, one is {3, 3, 3, 3, 0, 1, 2} or {3, 4, 5, 6, 3, 3, 3, 3, 3}
      }
    }
    return false;
  }
};


// recursive
class Solution {
public:
  int SearchHelper(int a[], int left, int right, int x) {
    int mid = (left + right)/2;
    if (a[mid] == x) {
      return mid;
    }
    if (right < left) {
      return -1;
    }
    if (a[left] < a[mid]) {
      if (x <= a[mid] && x >= a[left]) {
	return SearchHelper(a, left, mid-1, x);
      } else {
	return SearchHelper(a, mid+1, right, x);
      }
    } else if (a[mid] < a[left]) {
      if (x >= a[mid] && x <= a[right]) {
	return SearchHelper(a, mid+1, right, x);
      } else {
	return SearchHelper(a, left, mid-1, x);
      }
    } else if (a[left] == a[mid]) {
      if (a[mid] != a[right]) {
	return SearchHelper(a, mid+1, right, x);
      } else {
	int result = SearchHelper(a, left, mid-1, x);
	if (result == -1) {
	  return SearchHelper(a, mid+1, right, x);
	} else {
	  return result;
	}
      }
    }
    return -1;
  }
  bool search(int A[], int n, int target) {
    if (SearchHelper(A, 0, n-1, target) == -1) {
      return false;
    } else {
      return true;
    }
  }
};
