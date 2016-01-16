/* blocks[x][c], x = i - i%3 +j/3 because we want to map (i,j) to one cell of matrix A:
0 1 2
3 4 5
6 7 8

so first of all, we have to figure out which one should we choose in 0,3,6. We 
use i%3 to represent the offset that we can use to determine which row (i,j) is in A. And then we map this offset to one of 0,3,6 using i-i%3. After that, we have to figure out the column offset, which is j/3. Thus, (i,j) should be mapped into i-i%+j/3. For example, (3,4) should be mapped into 3-3%3+4/3=4
 */
class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    vector<vector<bool> > rows(9, vector<bool>(9, false));
    vector<vector<bool> > cols(9, vector<bool>(9, false));
    vector<vector<bool> > blocks(9, vector<bool>(9, false));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
	if (board[i][j] == '.') {
	  continue;
	}
	int c = board[i][j] - '1';
	if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c]) {
	  return false;
	}
	rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
      }
    }
    return true;
  }
};

// time: O(n^2), space: O(1)
class Solution {
public:
  bool isValidSudoku(const vector<vector<char>>& board) {
    bool used[9];

    for (int i = 0; i < 9; ++i) {
      fill(used, used + 9, false);

      for(int j = 0; j < 9; ++j)
	if (!check(board[i][j], used))
	  return false;
	
      fill(used, used + 9, false);

      for(int j = 0; j < 9;++j)
	if (!check(board[j][i], used))
	  return false;
    }

    for(int r = 0; r < 3; ++r)
      for (int c = 0; c < 3; ++c) {
	fill(used, used + 9, false);

	for (int i = r * 3; i < r * 3 + 3; ++i)
	  for (int j = c * 3; j < c * 3 + 3; ++j)
	    if (!check(board[i][j], used))
	      return false;
      }
      return true;
  }
  bool check(char ch, bool used[9]) {
    if (ch == '.') {
      return true;
    }
    if (used[ch - '1']) {
      return false;
    }
    used[ch - '1'] = true;
    return true;
  }
};
