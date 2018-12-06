// Idea: use three pointers, r for red that is the most right index of red,
// w for white that is the current index and b for blue that is the most
// left index of blue.
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int r = 0;
    int b = nums.size() - 1;
    for (int w = 0; w <= b; ++w) {
      if (nums[w] == 0) {
        swap(nums[w], nums[r]);
        ++r;
      } else if (nums[w] == 2) {
        swap(nums[w], nums[b]);
        --b;
        --w;
      }
    }
  }
};
