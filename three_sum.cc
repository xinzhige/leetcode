class Solution {  
public:  
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int>> result;
    size_t num_len = num.size();
    for (int i = 0; i < num_len; i++) {
      if ((i > 0) && (num[i] == num[i - 1])) {
        continue;
      }
      int l = i + 1;
      int r = num_len - 1;
      while (l < r) {
        int s = num[i] + num[l] + num[r];
        if (s > 0) {
          r -= 1;
        } else if (s < 0) {
          l += 1;
        } else {
          result.push_back(vector<int> {num[i], num[l], num[r]});
          while (num[l] == num[l + 1]) {
            l += 1;
          }
          while (num[r] == num[r - 1]) {
            r -= 1;
          }
          l += 1; 
          r -= 1;
        }
      }
    }
    return result;
  }
};
