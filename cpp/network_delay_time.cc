class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int, int>>> g(N + 1);
    for (const auto& t : times) {
      g[t[0]].emplace_back(t[1], t[2]);
    }
    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    pq.emplace(0, K);
    int u = 0;
    int v = 0;
    int w = 0;
    bool visited[N + 1] = {false};
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      u = t.second;
			if (!visited[u]) {
        for (const auto &to : g[u]) {
          v = to.first;
          w = to.second;
          if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
          }
        }
      }
			visited[u] = true;
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == INT_MAX ? -1 : ans;
  };
};
