class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<int> temp; 
    vector<vector<int> > result; 
    combine_res(n, k, 1, temp, result); 
    return result; 
  }

  void combine_res(int n, int k, int j, vector<int> temp, vector<vector<int> > &result) { 
    if(temp.size() == k) { 
      result.push_back(temp); 
      return; 
    }
    for(int i = j; i <= n; ++i) {
      temp.push_back(i);
      combine_res(n, k, ++j, temp, result);
      temp.pop_back();
    }
  }
};
