// Backtracking
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    vector<vector<int>> result;
    backtrack(n, k, 1, tmp, result);
    return result;
  }

private:
  void backtrack(int n, int k, int j, vector<int> tmp,
                 vector<vector<int>> &result) {
    if(tmp.size() == k) {
      result.push_back(tmp);
    } else {
      for(int i = j; i <= n; ++i, ++j) {
        tmp.push_back(i);
        backtrack(n, k, j + 1, tmp, result);
        tmp.pop_back();
      }
    }
  }
};


// Iterative
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
		int i = 0;
		vector<int> comb(k, 0);
		while (i >= 0) {
			comb[i] += 1;
			if (comb[i] > n) {
        i -= 1;
      } else if (i == k - 1) {
        result.push_back(comb);
      } else {
        i += 1;
        comb[i] = comb[i - 1];
			}
		}
		return result;
  }
};
