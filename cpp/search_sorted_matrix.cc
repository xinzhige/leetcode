// The first integer of each row is greater than the last integer of the previous row. time: O(lgn)
class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) {
      return false;
    }
    int cols = matrix[0].size();
    int begin = 0;
    int end = matrix.size()*cols - 1;
    while (begin <= end) {
      int middle = begin + (end - begin) / 2;
      if (matrix[middle/cols][middle%cols] == target) {
	return true;
      } else if (matrix[middle/cols][middle%cols] < target) {
	begin = middle + 1;
      } else {
	end = middle - 1;
      }
    }
    return false;
  }
};

// when the previous condition is not avaiable, time: O(m+n) but does not work well if the one dimention is small, e.x., matrix[2][10^5]
class Solution {
public:
  bool searchMatrix(vector<vector<int> > matrix, int target) {
    if (matrix[0].size() == 0) {
      return false;
    }
    int i = matrix.size() - 1;
    int j = 0;  //set indexes for bottom left element
    while (i >= 0 && j < matrix[0].size()) {
      if (matrix[i][j] == target) {
	return true;
      } else if ( matrix[i][j] > target) {
	i--;
      } else {
	j++;
      }
    }
    return false;
  }
};

// 
