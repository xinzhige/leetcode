class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        result = 0
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    result += 1
                    self.dfs(grid, i, j, dirs)
        return result


    def dfs(self, grid, i, j, dirs):
        if i >= 0 and i < len(grid) and j >= 0 and j < len(grid[0]) and \
           grid[i][j] == '1':
            grid[i][j] = '#'
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                self.dfs(grid, x, y, dirs)
