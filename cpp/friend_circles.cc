// DFS, time: O(n^2)
class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    vector<int> visited(M.size(), 0);
    int count = 0;
    for (int i = 0; i < M.size(); ++i) {
      if (visited[i] == 0) {
        dfs(M, visited, i);
        count += 1;
      }
    }
    return count;
  }
  void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
    for (int j = 0; j < M.size(); ++j) {
      if (M[i][j] == 1 && visited[j] == 0) {
        visited[j] = 1;
        dfs(M, visited, j);
      }
    }
  }
};


// BFS
class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    vector<int> visited(n, 0);
    int count = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (visited[i] == 0) {
        q.push(i);
        while (!q.empty()) {
          int s = q.front();
          q.pop();
          visited[s] = 1;
          for (int j = 0; j < n; ++j) {
            if (M[s][j] == 1 && visited[j] == 0) {
              q.push(j);
            }
          }
        }
        count += 1;
      }
    }
    return count;
  }
};

