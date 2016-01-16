// BFS, time: O(m*n), space: O(max(m, n))
class Solution {
public:
  void solve(vector<vector<char> > &board) {
    if (board.size() == 0 || board[0].size() == 0) {
      return;
    }
    m = board.size();
    n = board[0].size();
    for (int j = 0; j < n; ++j) {
      bfs(board, 0, j);
      bfs(board, m-1, j);
    }
    for (int i = 1; i < m -1; ++i) {
      bfs(board, i, 0);
      bfs(board, i, n - 1);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
    	if (board[i][j] == 'O') {
    	  board[i][j] = 'X';
    	}
    	if (board[i][j] == 'D') {
    	  board[i][j] = 'O';	
    	}
      }
    }
  }
private:
  queue<int> myqueue;
  vector<vector<char> > board;
  int m;
  int n;
  void fill(vector<vector<char> > &board, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'D';
    myqueue.push(x*n+y);
  }
  void bfs(vector<vector<char> > &board, int x, int y) {
    fill(board, x, y);
    while (!myqueue.empty()) {
      int curr = myqueue.front();
      myqueue.pop();
      int i = curr / n;
      int j = curr % n;
      fill(board, i-1, j);
      fill(board, i+1, j);
      fill(board, i, j-1);
      fill(board, i, j+1);
    }
  }
};

/* DFS, recursive but can not pass the large data testing set
class Solution {
public:
  void solve(vector<vector<char> > &board) {
    if (board.size() == 0 || board[0].size() == 0) return;
    const int m = board.size();
    const int n = board[0].size();
    for (int j = 0; j < n; ++j) {
      dfs(board, 0, j);
      dfs(board, m-1, j);
    }
    for (int i = 1; i < m -1; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
    	if (board[i][j] == 'O') {
    	  board[i][j] = 'X';
    	}
    	if (board[i][j] == 'D') {
    	  board[i][j] = 'O';	
    	}
      }
    }
  }

private:
  void dfs(vector<vector<char> > &board, int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'D';
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
  }
};
*/
