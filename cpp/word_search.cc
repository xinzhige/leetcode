// Suppose the board only contains the alphabet
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
    	if (dfs(board, word, 0, i, j)) {
    	  return true;
    	}
      }
    }
    return false;
  }
private:
  bool dfs(vector<vector<char>> &board, const string &word, 
	   int index, int x, int y) {
    if (index == word.size()) {
      return true;
    }
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
      return false;
    }
    if (board[x][y] != word[index]) {
      return false;
    }
    board[x][y] = '#';
    bool result = dfs(board, word, index + 1, x - 1, y) ||
      dfs(board, word, index + 1, x + 1, y) ||
      dfs(board, word, index + 1, x, y - 1) ||
      dfs(board, word, index + 1, x, y + 1);
    board[x][y] = word[index];
    return result;
  }
};
