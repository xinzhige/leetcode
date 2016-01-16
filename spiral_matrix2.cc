class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result(n,vector<int>(n,0));
    if (n == 0){
      return result;
    }
    int val = 1;
    int i = 0;
    int j = 0;
    result[0][0] = val++;
    while (val <= n*n){
      while (j+1 < n && result[i][j+1] == 0){   // keep going right
	result[i][++j] = val++;
      }
      while (i+1 < n && result[i+1][j] == 0){   // keep going down
	result[++i][j] = val++;
      }
      while (j-1 >= 0 && result[i][j-1] == 0){  // keep going left
	result[i][--j] = val++;
      }
      while (i-1 >= 0 && result[i-1][j] == 0){  // keep going up
	result[--i][j] = val++;
      }
    }
    return result;
  }
};
