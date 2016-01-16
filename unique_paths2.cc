// by a matrix, space: O(n^2)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int num_rows = obstacleGrid.size();
        int num_columns = obstacleGrid[0].size();
        vector<vector<int> > matrix(num_rows, vector<int> (num_columns, 0));
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        matrix[0][0] = 1;
        for (int i = 1; i < num_rows; ++i) {
            if (obstacleGrid[i][0] != 1) {
                matrix[i][0] = matrix[i-1][0];
            }
        }
        for (int j = 1; j < num_columns; ++j) {
            if (obstacleGrid[0][j] != 1) {
                matrix[0][j] = matrix[0][j-1];
            }
        }
        for (int i = 1; i < num_rows; ++i) {
            for (int j = 1; j < num_columns; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                }
            }
        }
        return matrix[num_rows-1][num_columns-1];
    }
};

// by a vector, space: O(n)
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int num_rows = obstacleGrid.size();  
    int num_columns = obstacleGrid[0].size();  
    if(num_rows == 0 || num_columns == 0 || obstacleGrid[0][0] == 1) {
      return 0;  
    }
    vector<int> my_vec(num_columns, 0);  
    my_vec[0] = 1;  
    for(int i = 0; i < num_rows; i++) {  
      for(int j = 0; j < num_columns; j++) {  
	if(obstacleGrid[i][j] == 1) {
	  my_vec[j] = 0;  
	} else if (j > 0) {
	  my_vec[j] += my_vec[j-1];  
	}
      }  
    }  
    return my_vec[num_columns-1];  
  }
};
