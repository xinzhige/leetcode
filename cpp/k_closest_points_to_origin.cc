// Time: O(nlogk), space: O(k)
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<vector<int>, vector<vector<int>>, Comparison> pq;
    for (const auto &p : points) {
      pq.push(p);
      if (pq.size() > K) {
        pq.pop();
      }
    }
    vector<vector<int>> result;
    while (!pq.empty()) {
      result.push_back(pq.top());
      pq.pop();
    }
    return result;
  }
  struct Comparison {
    bool operator() (const vector<int> &a, const vector<int> &b) {
      return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    }
  };
};


// Time: average O(n), space: O(n)
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    partition(points, 0, points.size() - 1, K);
    return vector(points.begin(), points.begin() + K);
  }

private:
  int dist(vector<int>& p) {
    return p[0]*p[0] + p[1]*p[1];
  }

  void partition(vector<vector<int>>& points, int l, int r, int K) {
    if (l < r && l < K && K <= r) {
      int x = l;
      int i = l;
      int j = r;
      int pivot = dist(points[x]);
      while (i < j) {
        for (; dist(points[i]) < pivot && i < j; ++i);
        for (; pivot < dist(points[j]) && i < j; --j);
        if (i < j) {
          swap(points[i], points[j]);
        }
      }
      partition(points, l, i - 1, K);
      partition(points, i + 1, r, K);
    }
  }
};
