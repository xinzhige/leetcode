class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<bool> used(num.size(), false);
    vector<int> path;
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    perm_helper(num, used, path, result);
    return result;
  }
  void perm_helper(vector<int> &num, vector<bool> &used, vector<int> &path, vector<vector<int> > &result) {
    if (num.size() == path.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < num.size(); ++i) {
      if (used[i] || 
	  (i != 0 && num[i] == num[i-1] && used[i-1])) {  // avoid the same ones after certain number used
	continue;
      }
      used[i] = true;
      path.push_back(num[i]);
      perm_helper(num, used, path, result);
      used[i] = false;
      path.pop_back();
    }
  }
};
