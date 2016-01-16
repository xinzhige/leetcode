class Solution {
public:
  int findMin(vector<int> &num) {
    int num_len = num.size();
    assert(num_len > 0);
    int begin = 0;
    int end = num_len - 1;
    int mid = 0;
    while (begin < end && num[begin] >= num[end]) {
      mid = begin + (end - begin) / 2;
      if (num[mid] > num[end]) {
        begin = mid + 1;
      } else if (num[mid] < num[begin]) {
        end = mid;
      } else {
        ++begin;
      }
    }
    return num[begin]; 
  }
};
