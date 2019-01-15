// O(n)
class Solution {
public:
  int fib(int N) {
    if (N < 2) {
      return N;
    }
    int first = 0;
    int second = 1;
    int result = 0;
    for (int i = 0; i < N - 1; ++i) {
      result = first + second;
      first = second;
      second = result;
    }
    return result;
  }
};


// O(lgn)
class Solution {
public:
  int fib(int N) {
    if (N < 2) {
      return N;
    }
    int a[2][2] = {{1, 1}, {1, 0}};
    int f[2][2] = {{1, 0}, {0, 1}};
    pow(f, a, N - 1);
    return f[0][0];
  }
  void pow(int a[2][2], int b[2][2], int n) {
    while (n > 0) {
      if ((n & 1) > 0) {
        multiply(a, a, b);
      }
      n >>= 1;
      multiply(b, b, b);
    }
  }
  void multiply(int c[2][2], int a[2][2], int b[2][2]) {
    int t[4];
    t[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    t[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    t[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    t[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    c[0][0] = t[0];
    c[0][1] = t[1];
    c[1][0] = t[2];
    c[1][1] = t[3];
  }
};
