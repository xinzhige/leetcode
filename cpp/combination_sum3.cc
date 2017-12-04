class Solution {
public:
  vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> combination;
    combinationSum3(result, combination, 1, k, n);
    return result;
  }
private:
  void combinationSum3(vector<vector<int>> &res, vector<int> &combination, int start, int k, int n) {
    if (k == 0 && n == 0) {
      res.push_back(combination);
      return;
    }
    for (int i = start; i <= num; ++i) {
      combination.emplace_back(i);
      combinationSum3(res, combination, i + 1, k - 1, n - i);
      combination.pop_back();
    }
  }
  const int num = 9;
};
