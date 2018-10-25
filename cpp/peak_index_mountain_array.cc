class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int begin = 0;
    int end = A.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (A[mid] > A[mid+1]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};
