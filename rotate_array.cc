class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    size_t nums_length = nums.size(); 
    if (k < 2 || k % nums_length == 0) {
      return;	    
    }
    k = k % nums_length;
    reverse(nums, 0, nums_length - k - 1);
    reverse(nums, nums_length - k, nums_length - 1);
    reverse(nums, 0, nums_length - 1);
  }

  void reverse(vector<int> &a, int begin, int end) {
    while (begin < end) {
      swap(a[begin], a[end]);
      begin += 1;
      end -= 1;
    } 
  }

  void swap(int &x, int &y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
  }
};
