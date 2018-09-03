class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    unordered_map<int, int> count;
    for (const auto &num : nums) {
      count[num] += 1;
    }
    for (const auto &kv : count) {
      pq.push({kv.second, kv.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> result;
    for (; !pq.empty(); pq.pop()) {
      result.push_back(pq.top().second);
    }
    return result;
  }
};
