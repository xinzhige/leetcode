// Space: O(1)
class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    dfs(num, 0, result);
    return result;
  }
  void dfs(vector<int> &num, int pos, vector<vector<int>> &result) {
    if(pos == num.size()) {
      result.push_back(num);
    } else {
      for(int i = pos; i < num.size(); ++i) {
        swap(num[i], num[pos]);
        dfs(num, pos+1, result);
        swap(num[i], num[pos]);
      }
    }
  }
};
