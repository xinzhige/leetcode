// Idea: store the ugly sequence in array and the next ugly number can be
// tracked by node's prime number and the current smallest ugly number
// it meets in the sequence.
// Push the nodes (value, index, prime) in heap (size k).
// Time: O(nlogk)
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ugly(n, 0);
    priority_queue<Node, vector<Node>, Comparison> pq;
    for (const int &p : primes) {
      pq.emplace(p, 1, p);
    }
    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
      ugly[i] = pq.top().val;
      // Keep popping in case there are duplicates ugly number
      // but push its next value into heap
      while (pq.top().val == ugly[i]) {
        auto next = pq.top();
        pq.pop();
        pq.emplace(next.prime * ugly[next.idx], next.idx + 1, next.prime);
      }
    }
    return ugly[n - 1];
  }
  struct Node {
    Node(int v, int i, int p) : val(v), idx(i), prime(p) {}
    int val;
    int idx;
    int prime;
  };
  struct Comparison {
    bool operator() (const Node &a, const Node &b) {
      return a.val > b.val;
    }
  };
};
