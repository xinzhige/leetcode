class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> result;
    vector<int> tmp;
    dfs(result, tmp, n, 2);
    return result;
  }
  void dfs(vector<vector<int>>& result, vector<int> tmp, int n, int start) {
    for (int i = start; i * i <= n; ++i) {
      if (n % i == 0) {
        vector<int> new_tmp = tmp;
        new_tmp.emplace_back(i);
        dfs(result, new_tmp, n/i, i);
        new_tmp.emplace_back(n/i);
        result.emplace_back(new_tmp);
      }
    }
  }
};

class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> result;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        vector<vector<int>> tmp = getFactors(n / i);
        vector<int> out{i, n / i};
        result.emplace_back(out);
        for (auto a : tmp) {
          if (i <= a[0]) {
            a.insert(a.begin(), i);
            result.emplace_back(a);
          }
        }
      }
    }
    return result;
  }
};
