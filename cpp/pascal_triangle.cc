class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    if (numRows <= 0) {
      return result;
    }
    vector<int> curr;
    curr.push_back(1);
    result.push_back(curr);
    for (int i = 2; i <= numRows; ++i) {
      vector<int> prev = curr;
      curr.clear();
      for (int j = 0; j < i; ++j) {
        if (j == 0 || j == i-1) {
	  curr.push_back(1);
        } else {
	  int temp = prev[j-1] + prev[j];
	  curr.push_back(temp);
        }
      }
      result.push_back(curr);
    }
    return result;
  }
};

// return the last row of k rows pascal's triangle
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> array;
    for (int i = 0; i <= rowIndex; ++i) {
      for (int j = i-1; j > 0; --j){
	array[j] = array[j-1] + array[j];
      }
      array.push_back(1);
    }
    return array;
  }
};
