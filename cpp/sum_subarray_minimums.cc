class Solution {
public:
  int sumSubarrayMins(vector<int>& A) {
    int res = 0, n = A.size(), mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<pair<int, int>> s1,s2;
    for (int i = 0; i < n; ++i) {
      int count = 1;
      while (!s1.empty() && s1.top().first > A[i]) {
        count += s1.top().second;
        s1.pop();
      }
      s1.push({A[i], count});
      left[i] = count;
    }
    for (int i = n - 1; i >= 0; --i) {
      int count = 1;
      while (!s2.empty() && s2.top().first >= A[i]) {
        count += s2.top().second;
        s2.pop();
      }
      s2.push({A[i], count});
      right[i] = count;
    }
    for (int i = 0; i < n; ++i)
      res = (res + A[i] * left[i] * right[i]) % mod;
    return res;
  }
};


class Solution {
public:
  int sumSubarrayMins(vector<int>& A) {
    int res = 0, n = A.size(), mod = 1e9 + 7, j, k;
    stack<int> s;
    for (int i = 0; i <= n; ++i) {
      while (!s.empty() && A[s.top()] > (i == n ? 0 : A[i])) {
        j = s.top();
        s.pop();
        k = s.empty() ? -1 : s.top();
        res = (res + A[j] * (i - j) * (j - k)) % mod;
      }
      s.push(i);
    }
    return res;
  }
};
