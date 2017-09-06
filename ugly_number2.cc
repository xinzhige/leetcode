class Solution {
public:
  int nthUglyNumber(int n) {
    if(n <= 0) {
      return 0;
    }
    int t2 = 0;
    int t3 = 0;
    int t5 = 0; 
    vector<int> k(n);
    k[0] = 1;
    for(int i = 1; i < n ; i++) {
      k[i] = min(k[t2]*2, min(k[t3]*3, k[t5]*5));
      if ((k[i] / 2) == k[t2]) {
        t2 += 1;
      }
      if ((k[i] / 3) == k[t3]) {
        t3 += 1;
      }
    if ((k[i] / 5) == k[t5]) {
        t5 += 1;
      }
    }
    return k[n-1];
  }
};
