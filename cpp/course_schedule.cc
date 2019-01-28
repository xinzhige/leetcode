// BFS, do not forget line 18.
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    auto graph = build_graph(numCourses, prerequisites);
    vector<int> indegrees = compute_indegree(graph);
    for (int i = 0; i < numCourses; ++i) {
      int j = 0;
      for (; j < numCourses; ++j) {
        if (indegrees[j] == 0) {
          break;
        }
      }
      if (j == numCourses) {
        return false;
      }
      indegrees[j] = -1;
      for (const int &neighbor : graph[j]) {
        indegrees[neighbor] -= 1;
      }
    }
    return true;
  }
private:
  vector<vector<int>> build_graph(int numCourses,
                                  vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (const auto &pre : prerequisites) {
      graph[pre.second].push_back(pre.first);
    }
    return graph;
  }
  vector<int> compute_indegree(vector<vector<int>>& graph) {
    vector<int> indegrees(graph.size(), 0);
    for (const auto & neighbors : graph) {
      for (const int &neighbor : neighbors) {
        indegrees[neighbor] += 1;
      }
    }
    return indegrees;
  }
};


// DFS
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> visit(numCourses, 0);
    for (const auto &p : prerequisites) {
      graph[p.second].push_back(p.first);
    }
    for (int i = 0; i < numCourses; ++i) {
      if (!canFinishDFS(graph, visit, i)) {
        return false;
      }
    }
    return true;
  }
private:
  bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i) {
    if (visit[i] == -1) {
      return false;
    }
    if (visit[i] == 1) {
      return true;
    }
    visit[i] = -1;
    for (const auto &neighbor : graph[i]) {
      if (!canFinishDFS(graph, visit, neighbor)) {
        return false;
      }
    }
    visit[i] = 1;
    return true;
  }
};
