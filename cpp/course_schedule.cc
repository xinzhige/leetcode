// BFS
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int> > graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);
    for (const auto & a : prerequisites) {
      graph[a.second].emplace_back(a.first);
      in[a.first] += 1;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0) {
	q.emplace(i);
      }
    }
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      for (const auto & a : graph[t]) {
	in[a] -= 1;
	if (in[a] == 0) {
	  q.emplace(a);
	}
      }
    }
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] != 0) {
	return false;
      }
    }
    return true;
  }
};


// DFS
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
    vector<vector<int> > graph(numCourses, vector<int>(0));
    vector<int> visit(numCourses, 0);
    for (const auto & a : prerequisites) {
      graph[a.second].emplace_back(a.first);
    }
    for (int i = 0; i < numCourses; ++i) {
      if (!canFinishDFS(graph, visit, i)) {
	return false;
      }
    }
    return true;
  }
private:
  bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
    if (visit[i] == -1) {
      return false;
    }
    if (visit[i] == 1) {
      return true;
    }
    visit[i] = -1;
    for (const auto a : graph[i]) {
      if (!canFinishDFS(graph, visit, a)) {
	return false;
      }
    }
    visit[i] = 1;
    return true;
  }
};
