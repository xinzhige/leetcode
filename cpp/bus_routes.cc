class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    unordered_map<int, unordered_set<int>> to_route;
    for (int i = 0; i < routes.size(); ++i) {
      for (int &j : routes[i]) {
        to_route[j].insert(i);
      }
    }
    queue<pair<int, int>> bfs;
    bfs.emplace(S, 0);
    unordered_set<int> seen = {S};
    while (!bfs.empty()) {
      int stop = bfs.front().first;
      int level = bfs.front().second;
      bfs.pop();
      if (stop == T) {
        return level;
      }
      for (auto &route_i : to_route[stop]) {
        for (auto &next_stop : routes[route_i]) {
          if (seen.count(next_stop) == 0) {
            seen.insert(next_stop);
            bfs.emplace(next_stop, level + 1);
          }
        }
        routes[route_i].clear();
      }
    }
    return -1;
  }
};
