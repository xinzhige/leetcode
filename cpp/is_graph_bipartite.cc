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
  bool valid(vector<vector<int>>& graph, int color, int node,
             vector<int>& colors) {
    if (colors[node] != 0) {
      return colors[node] == color;
    }
    colors[node] = color;
    for (const int &neighbor : graph[curr]) {
      if (!valid(graph, -1 * color, neighbor, colors)) {
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
          int node = q.front();
          q.pop();
          for (const int &neighbor : graph[node]) {
            if (colors[neighbor] == 0) {
              colors[neighbor] = -1 * colors[node];
              q.push(neighbor);
            } else if (colors[neighbor] == colors[node]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
