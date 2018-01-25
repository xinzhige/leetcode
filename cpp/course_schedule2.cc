class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
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
      result.emplace_back(t);
      q.pop();
      for (const auto & a : graph[t]) {
    	in[a] -= 1;
    	if (in[a] == 0) {
    	  q.emplace(a);
    	}
      }
    }
    if (result.size() != numCourses) {
        result.clear();
    }
    return result;        
  }
};
