class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegrees(numCourses, 0);
    for (const auto &pre : prerequisites) {
      graph[pre.second].push_back(pre.first);
      indegrees[pre.first] += 1;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegrees[i] == 0) {
        q.push(i);
      }
    }
    vector<int> result;
    while (!q.empty()) {
      int node = q.front();
      result.push_back(node);
      q.pop();
      for (const auto &neighbor : graph[node]) {
        indegrees[neighbor] -= 1;
        if (indegrees[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }
    if (result.size() != numCourses) {
      result.clear();
    }
    return result;
  }
};
