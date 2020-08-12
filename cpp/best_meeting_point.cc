class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> columns;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    rows.push_back(row);
                }
            }
        }
        for (int col = 0; col < grid[0].size(); col++) {
            for (int row = 0; row < grid.size(); row++) {
                if (grid[row][col] == 1) {
                    columns.push_back(col);
                }
            }
        }
        return minDistance1D(rows) + minDistance1D(columns);
    }
    int minDistance1D(vector<int> points) {
        int distance = 0;
        int i = 0;
        int j = points.size() - 1;
        while (i < j) {
            distance += points[j] - points[i];
            i++;
            j--;
        }
        return distance;
    }
};