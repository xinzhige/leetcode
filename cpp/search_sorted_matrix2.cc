class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false; 
        }
        int col = matrix[0].size() - 1;
        int row = 0;
        while (col >= 0 && row < matrix.size()) {
            if (matrix[row][col] == target) {
                return true; 
            } else if (matrix[row][col] < target) {
                row += 1; 
            } else {
                col -= 1; 
            } 
        }
        return false;
    }
};
