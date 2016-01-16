class Solution {
public:
  void printResult(vector<int> A, int n, vector<vector<string> >& result){
    vector<string> curr_row;
    for(int i = 0; i < n; ++i) {
      string str(n, '.');
      str[A[i]] = 'Q';
      curr_row.push_back(str);
    }
    result.push_back(curr_row);
  }
  bool isValid(vector<int> A, int row){
    for (int i = 0; i < row; ++i) {
      if ((A[i] == A[row]) || (abs(A[i] - A[row]) == (row - i))){
	    return false;
      }
    }
    return true;
  }
  void nQueens(vector<int> A, int curr, int n, vector<vector<string> >& result){
    if (curr == n) {
      printResult(A, n, result);
    } else {
      for (int i = 0; i < n; ++i) {
    	A[curr] = i;
    	if (isValid(A, curr)) {
    	  nQueens(A, curr+1, n, result);
    	}
      }
    }
  }
  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<int> A(n, 0);
    nQueens(A, 0, n, result);
    return result;
  }
};

/*
// fast version using bitmask
class Solution 
{
    int n;
    string getNq(int p)
    {
        string s(n, '.');
        s[p] = 'Q';
        return s;
    }
    void nQueens(int p, int l, int m, int r, vector<vector<string>> &res)
    {
        static vector<string> ans;
        if (p >= n)
        {
            res.push_back(ans);
            return ;
        }
        int mask = l | m | r;
        for (int i = 0, b = 1; i < n; ++ i, b <<= 1)
            if (!(mask & b))
            {
                ans.push_back(getNq(i));
                nQueens(p + 1, (l | b) >> 1, m | b, (r | b) << 1, res);
                ans.pop_back();
            }
    }
public:
    vector<vector<string> > solveNQueens(int n) 
    {
        this->n = n;
        vector<vector<string>> res;
        nQueens(0, 0, 0, 0, res);
        return res;
    }
};
*/
