// Idea: if nums[mid] >= n-mid, then there are at least n-mid papers with
// more than nums[mid] citations. The final result should be n-low or
// n-(high+1).
class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (citations[mid] >= n - mid) {
        high = mid - 1;
      }else {
        low = mid + 1;
      }
    }
    return n - low;
  }
};
