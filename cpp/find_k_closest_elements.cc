// Idea: binary-search for where the resulting elements start in the array.
// It's the first index i such that arr[i] is better than arr[i+k] (with
// "better" meaning closer to or equally close to x)
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int low = 0;
    int high = arr.size() - k;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (x > arr[mid]) {
        if (x - arr[mid] > arr[mid+k] - x) {
          low = mid + 1;
        } else {
          high = mid;
        }
      } else {
        high = mid;
      }
    }
    vector<int> result(arr.begin() + low, arr.begin() + low + k);
    return result;
  }
};


// The previous one can be optimized, if x <= arr[mid], then x <= arr[mid+k].
// x - arr[mid] can not be larger than arr[mid+k] - x.
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int low = 0;
    int high = arr.size() - k;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (x - arr[mid] > arr[mid+k] - x) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    vector<int> result(arr.begin() + low, arr.begin() + low + k);
    return result;
  }
};
