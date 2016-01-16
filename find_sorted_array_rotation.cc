int FindSortedArrayRotation(int A[], int n) {
  int left = 0;
  int right = n - 1;
  int mid;
  while (A[left] > A[right]) {
    mid = left + (right - left) / 2;
    if (A[mid] > A[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}
