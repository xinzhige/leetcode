class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> tmp;
    backtrack(candidates, 0, target, tmp, result);
    return result;
  }
private:
  void backtrack(vector<int>& candidates, int start, int gap,
                 vector<int>& tmp, vector<vector<int>>& result) {
    if (gap == 0) {
      result.push_back(tmp);
    } else if (gap > 0) {
      for (int i = start; i < candidates.size(); ++i) {
        tmp.push_back(candidates[i]);
        backtrack(candidates, i, gap - candidates[i], tmp, result);
        tmp.pop_back();
      }
    }
  }
};
