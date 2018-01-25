public class Solution {
    int m, n;
    char[][] board;
    Queue<Integer> queue = new LinkedList<Integer>();
    
    void fill(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') return;
        queue.offer(x*n+y);
        board[x][y] = 'D';
    }
    
    void bfs(int x, int y) {
        fill(x,y);
        
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            int i = curr / n;
            int j = curr % n;
            
            fill(i-1, j);
            fill(i+1, j);
            fill(i, j-1);
            fill(i, j+1);
        }
    }
    
    public void solve(char[][] board) {
        if (board == null || board.length == 0) return;
        this.board = board;
        m = board.length;
        n = board[0].length;
        
        for (int j = 0; j < n; j++) {
            bfs(0, j);
            bfs(m-1, j);
        }
        
        for (int i = 1; i < m-1; i++) {
            bfs(i, 0);
            bfs(i, n-1);
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'D') board[i][j] = 'O';
            }
    }
}
