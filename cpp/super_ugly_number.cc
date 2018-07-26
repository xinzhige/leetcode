class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ugly(n);
    int m = primes.size();
    vector<int> idx(m);
    vector<int> val(m, 1);
    int next = 1;
    for (int i = 0; i < n; ++i) {
      ugly[i] = next;
      next = INT_MAX;
      for (int j = 0; j < m; ++j) {
        if (val[j] == ugly[i]) {
          val[j] = ugly[idx[j]] * primes[j];
          idx[j] += 1;
        }
        next = min(next, val[j]);
      }
    }
    return ugly.back();
  }
};
