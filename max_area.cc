// brute force
class Solution {
public:
  int maxArea(vector<int> &height) {
    int num_lines = height.size();
    if (num_lines <= 1) {
      return 0;
    }
    int curr_max;
    for (int i = 0; i < num_lines-1; ++i) {
      curr_max = min(height[i], height[i+1]);
      for (int j = i + 2; j < num_lines; ++j) {
	int temp = min(height[j], height[i])*(j-i);
	if (temp > curr_max) {
	  curr_max = temp;
	}
      }
    }
    return curr_max;
  }
};

// if aj < ai, then we do not consider aj as a possible line
class Solution {
public:
  int maxArea(vector<int> &height) {
    int num_lines = height.size();
    if (num_lines <= 1) {
      return 0;
    }
    int curr_max_area = min(height[0], height[1]);
    int curr_max_height = height[0];
    for (int i = 0; i < num_lines-1; ++i) {
      if (i != 0) {
	if (height[i] > curr_max_height) {
	  curr_max_height = height[i];
	} else {
	  continue;
	}
      }
      for (int j = i + 2; j < num_lines; ++j) {
	int temp = min(height[j], height[i])*(j-i);
	if (temp > curr_max_area) {
	  curr_max_area = temp;
	}
      }
    }
    return curr_max_area;
  }
};

// by greedy algorithm, 2 pointers point to begin and end of the vector, time: O(n)
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;
    while(left < right) {
	int curr_area = min(height[left], height[right]) * (right - left);
	if(curr_area > result) {
	  result = curr_area;
	}
	if(height[left] <= height[right]) {
	  left++;
	} else {
	  right--;
	}
      }
    return result;
  }
};
