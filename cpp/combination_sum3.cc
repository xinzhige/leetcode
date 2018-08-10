class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> comb;
    combinationSum3(result, comb, 1, k, n);
    return result;
  }

private:
  void combinationSum3(vector<vector<int>> &result, vector<int> &comb,
                       int start, int k, int n) {
    if (k == 0 && n == 0) {
      result.push_back(comb);
    } else {
      for (int i = start; i <= NUM; ++i) {
        comb.push_back(i);
        combinationSum3(result, comb, i + 1, k - 1, n - i);
        comb.pop_back();
      }
    }
  }

private:
  const int NUM = 9;
};
