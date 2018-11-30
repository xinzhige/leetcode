// Idea: build an array that each element is the sum all the weights
// so far at point i. Then, random pick a value in the range [0, total_sum].
// At last, binary search the index of number that is the first larger than it.
class Solution {
public:
  Solution(vector<int> w) {
    sum = w;
    for (int i = 1; i < w.size(); ++i) {
      sum[i] = sum[i-1] + w[i];
    }
  }

  int pickIndex() {
    int x = rand() % sum.back();
    int left = 0;
    int right = sum.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (sum[mid] <= x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }

private:
  vector<int> sum;
};
