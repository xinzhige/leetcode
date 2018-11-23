// It is the same as 785 if change dislikes to graph representation.
class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N + 1);
    vector<int> color(N + 1, 0);
    for (const auto &d : dislikes) {
      graph[d[0]].push_back(d[1]);
      graph[d[1]].push_back(d[0]);
    }
    for (int i = 1; i <= N; ++i) {
      if (color[i] == 0 && !dfs(graph, color, i, 0)) {
        return false;
      }
    }
    return true;
  }
  bool dfs(vector<vector<int>>& graph, vector<int>& color, int node,
           int c) {
    if (color[node] == 1) {
      return color[node] == c;
    }
    color[node] = c;
    for (const int &neighbor : graph[node]) {
      if (!dfs(graph, color, neighbor, c ^ 1)) {
        return false;
      }
    }
    return true;
  }
};
