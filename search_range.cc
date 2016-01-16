class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
      int start = firstGreaterEqual(A, n, target);
      vector<int> res;
      if (start == n  || A[start] != target) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
      }
      int end = firstGreaterEqual(A, n, target + 1) - 1;
      res.push_back(start);
      res.push_back(end);
    }
    int firstGreaterEqual(int A[], int n, int target) {
        int low = 0, high = n;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
  };

/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
      vector<int> result;
      int begin = 0;
      int end = n-1;
      int middle;
      while(begin < end) {
        middle = (begin + end) / 2;
        if (A[middle] < target) {
          begin = middle + 1;
        } else {
          end = middle;
        }
      }
      if ((begin == end) && (A[end] == target)) {
        result.push_back(begin);
      }
      begin = 0;
      end = n-1;
      while(begin <= end) {
        middle = (begin+end) / 2;
        if (A[middle] > target) {
          end = middle - 1;
        } else if (A[middle] < target) {
          begin = middle + 1;
        } else {
          if (A[middle+1] != target) {
    	    result.push_back(middle);
    	    break;
          } else {
    	    begin += 1;
          }
        }
      }
      if (result.size() == 0) {
          result.assign(2, -1);
      }
      if (result.size() == 1) {
          result.push_back(result.back());
      }
      return result;
    }
};
*/
