class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if (matrix.empty())
      return result;
    int beginX = 0, endX = matrix[0].size() - 1;
    int beginY = 0, endY = matrix.size() - 1;
    while (true) {
      // from left to right
      for (int j = beginX; j <= endX; ++j) 
	result.push_back(matrix[beginY][j]);
      if (++beginY > endY) 
	break;
      // from top to bottom
      for (int i = beginY; i <= endY; ++i)
	result.push_back(matrix[i][endX]);
      if (beginX > --endX)
	break;
      // from right to left
      for (int j = endX; j >= beginX; --j)
	result.push_back(matrix[endY][j]);
      if (beginY > --endY)
	break;
      // from bottom to top
      for (int i = endY; i >= beginY; --i)
	result.push_back(matrix[i][beginX]);
      if (++beginX > endX)
	break;
    }
    return result;
  }
};
