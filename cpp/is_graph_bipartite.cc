// DFS, color every node such that two neighbors do not have the same color.
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    // 0 represents no coloring, 1 and -1 represent two colors.
    vector<int> colors(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] == 0 && !valid(graph, 1, i, colors)) {
        return false;
      }
    }
    return true;
  }
  bool valid(vector<vector<int>>& graph, int color, int curr,
             vector<int>& colors) {
    if (colors[curr] != 0) {
      return colors[curr] == color;
    }
    colors[curr] = color;
    for (const auto &i : graph[curr]) {
      if (!valid(graph, -1 * color, i, colors)) {
        return false;
      }
    }
    return true;
  }
};


// Iterative
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] == 0) {
        colors[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
          auto t = q.front();
          q.pop();
          for (const auto &n : graph[t]) {
            if (colors[n] == 0) {
              colors[n] = -1 * colors[t];
              q.push(n);
            } else if (colors[n] == colors[t]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
