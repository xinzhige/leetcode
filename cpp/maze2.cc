// DFS
class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    m = maze.size();
    n = maze[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[start[0]][start[1]] = 0;
    dfs(maze, start, dist);
    return dist[destination[0]][destination[1]] == INT_MAX ? -1 :
      dist[destination[0]][destination[1]];
  }
  void dfs(vector<vector<int>>& maze, vector<int> &start,
           vector<vector<int>> &dist) {
    for (const auto &dir : dirs) {
      int x = start[0] + dir[0];
      int y = start[1] + dir[1];
      int count = 0;
      while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
        x += dir[0];
        y += dir[1];
        count += 1;
      }
      if (dist[start[0]][start[1]] + count <
          dist[x - dir[0]][y - dir[1]]) {
        dist[x - dir[0]][y - dir[1]] = dist[start[0]][start[1]] + count;
        vector<int> tmp{x - dir[0], y - dir[1]};
        dfs(maze, tmp, dist);
      }
    }
  }

private:
  vector<vector<int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int m = 0;
  int n = 0;
};


// Dijkstra and priority queue, time: O(mnlg(mn)), space: O(mn)
class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    m = maze.size();
    n = maze[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[start[0]][start[1]] = 0;
    dijkstra(maze, start, dist);
    return dist[destination[0]][destination[1]] == INT_MAX ? -1 :
      dist[destination[0]][destination[1]];
  }
  void dijkstra(vector<vector<int>>& maze, vector<int>& start,
                vector<vector<int>>& dist) {
    priority_queue<State, vector<State>, MyComparison> pq;
    pq.emplace(start[0], start[1], 0);
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      if (dist[t.x][t.y] >= t.d) {
        for (const auto &dir : dirs) {
          int x = t.x + dir[0];
          int y = t.y + dir[1];
          int count = 0;
          while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
            x += dir[0];
            y += dir[1];
            count += 1;
          }
          if (dist[t.x][t.y] + count < dist[x - dir[0]][y - dir[1]]) {
            dist[x - dir[0]][y - dir[1]] = dist[t.x][t.y] + count;
            pq.emplace(x - dir[0], y - dir[1], dist[x - dir[0]][y - dir[1]]);
          }
        }
      }
    }
  }

private:
  struct State {
    State(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
    int x;
    int y;
    int d;
  };

  struct MyComparison {
    bool operator() (const State &s1, const State &s2) {
      return s1.d < s2.d;
    }
  };
  vector<vector<int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int m = 0;
  int n = 0;
};
