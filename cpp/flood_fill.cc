class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    m = image.size();
    n = image[0].size();
    int oldColor = image[sr][sc];
    if (oldColor != newColor) {
      dfs(image, sr, sc, oldColor, newColor);
    }
    return image;
  }
  void dfs(vector<vector<int>>& image, int i, int j, int oldColor,
           int newColor) {
    if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == oldColor) {
      image[i][j] = newColor;
      for (const auto &dir : dirs) {
        dfs(image, i + dir[0], j + dir[1], oldColor, newColor);
      }
    }
  }
private:
  vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int m = 0;
  int n = 0;
};
