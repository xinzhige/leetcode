// Idea: find the first element that is larger than its right neighbor.
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int begin = 0;
    int end = A.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (A[mid] < A[mid+1]) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};
