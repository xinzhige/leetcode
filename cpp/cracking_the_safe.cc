// Idea: the result length should be k^n+n-1 and each n characters should be
// overlapped by n-1 characters to make sure the result length is minimized.
// Note: the inner for loop should start from k-1 to 0 because the result
// is initialized to string(n, '0').
// Otherwise, the loop breaks early because "0x...x" always in the set first.
// If it is initialized to be string(n, '0'+k-1), then k starts from 0 to k-1.
class Solution {
public:
  string crackSafe(int n, int k) {
    string result(n, '0');
    unordered_set<string> visited;
    visited.insert(result);
    int m = pow(k, n);
    for (int i = 0; i < m; ++i) {
      string prev = result.substr(result.size() - n + 1, n - 1);
      for (int j = k - 1; j >= 0; --j) {
        string curr = prev + to_string(j);
        if (!visited.count(curr)) {
          visited.insert(curr);
          result += to_string(j);
          break;
        }
      }
    }
    return result;
  }
};

// Inverse Burrows-Wheeler Transform
class Solution {
public:
  string crackSafe(int n, int k) {
    int M = pow(k, n - 1);
    vector<int> P(M * k, 0);
    for (int i = 0; i < k; ++i) {
      for (int q = 0; q < M; ++q) {
        P[i * M + q] = q * k + i;
      }
    }
    string result = "";
    for (int i = 0;i < M * k; ++i) {
      int j = i;
      while (P[j] >= 0) {
        result.append(to_string(j / M));
        int v = P[j];
        P[j] = -1;
        j = v;
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      result.push_back('0');
    }
    return result;
  }
};
