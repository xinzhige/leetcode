class KthLargest {
public:
  KthLargest(int k, vector<int> nums) {
    _k = k;
    for (const auto &x : nums) {
      pq.push(x);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > _k) {
      pq.pop();
    }
    return pq.top();
  }
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int _k = 0;
};
