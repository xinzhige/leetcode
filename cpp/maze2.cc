// Dijkstra and priority queue, time: O(mnlg(mn)), space: O(mn)
// Note: priority queue contains all the vertices that have shortest
// distance from start.
class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) {
      return -1;
    }
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
    priority_queue<State, vector<State>, Comparison> pq;
    pq.emplace(start[0], start[1], 0);
    vector<vector<int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      for (const auto &dir : dirs) {
        int x = t.x;
        int y = t.y;
        int d = 0;
        while (x + dir[0] >= 0 && x + dir[0] < m &&
               y + dir[1] >= 0 && y + dir[1]< n &&
               maze[x + dir[0]][y + dir[1]] == 0) {
          x += dir[0];
          y += dir[1];
          d += 1;
        }
        if (dist[t.x][t.y] + d < dist[x][y]) {
          dist[x][y] = dist[t.x][t.y] + d;
          pq.emplace(x, y, dist[x][y]);
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

  struct Comparison {
    bool operator() (const State &s1, const State &s2) {
      return s1.d > s2.d;
    }
  };
  int m = 0;
  int n = 0;
};
