// this problem can be transformed into the Fibonacci problem because f(n) = f(n-1) + f(n-2)
class Solution {
public:
  int climbStairs(int n) {
    int first = 0;
    int second = 1;
    int sum = 1;
    for (int i = 1; i <= n; ++i) {
      sum  = first + second;
      first = second;
      second = sum;
    }
    return sum;
  }
};


// lg(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<int>> A(2, vector<int>(2, 0));
        vector<vector<int>> B(2, vector<int>(2, 0));
        A = {{1, 0}, {0, 1}};
        B = {{1, 1}, {1, 0}};
        matrixPow(A, B, n);
        return A[0][0];
    }
private:
    void matrixMul(vector<vector<int>> &C, vector<vector<int>> &A, vector<vector<int>> &B) {
        int t[4];
        t[0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        t[1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        t[2] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        t[3] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        C[0][0] = t[0];
        C[0][1] = t[1];
        C[1][0] = t[2];
        C[1][1] = t[3];
    }
    void matrixPow(vector<vector<int>> &A, vector<vector<int>> &B, int n) {
        while (n > 0) {
            if (n & 1) {
                matrixMul(A, A, B);
            }
            matrixMul(B, B, B);
            n >>= 1;
        }
    }
};
