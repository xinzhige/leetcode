// Idea: four pointers, two for index moving forward and backward and the rest
// point to the highest unit on the left and right so far.
class Solution {
public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;
    int left_max = 0;
    int right_max = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= left_max) {
          left_max = height[left];
        } else {
          result += left_max - height[left];
        }
        left += 1;
      } else {
        if (height[right] >= right_max) {
          right_max = height[right];
        } else {
          result += right_max - height[right];
        }
        right -= 1;
      }
    }
    return result;
  }
};
