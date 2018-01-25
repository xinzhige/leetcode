class Solution {
public:
  vector<vector<int>> subsets(vector<int> &S) {
    vector<vector<int>> result(1);
    sort(S.begin(), S.end());
    for (int i = 0; i < S.size(); ++i) {
      int size = result.size();
      for (int j = 0; j < size; ++j) {
	result.emplace_back(result[j]);
	result.back().emplace_back(S[i]);
      }
    }
    return result;
  }
};

// DFS
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &S) {
    vector<vector<int>> result;
    vector<int> out;
    sort(S.begin(), S.end());
    getSubsets(S, 0, out, result);
    return result;
  }

private:
  void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int> > &result) {
    result.emplace_back(out);
    for (int i = pos; i < S.size(); ++i) {
      out.emplace_back(S[i]);
      getSubsets(S, i + 1, out, result);
      out.pop_back();
    }
  }
};
