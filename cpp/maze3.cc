class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<char> turns = {'d', 'u', 'r', 'l'};
        int m= maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Point, vector<Point>, cmp> min_heap;
        min_heap.emplace(ball[0], ball[1], 0, "");
        while (!min_heap.empty()) {
            Point cur_point = min_heap.top();
            min_heap.pop();
            int row = cur_point.row;
            int col = cur_point.col;
            if (row == hole[0] && col == hole[1]) {
                return cur_point.path;
            }
            if (!visited[row][col]) {
                visited[row][col] = true;
                for (int i = 0; i < 4; i++) {
                    int r = row;
                    int c = col;
                    int dist = cur_point.dist;
                    while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0 && (r != hole[0] || c != hole[1])) {
                        r += dirs[i][0];
                        c += dirs[i][1];
                        dist++;
                    }
                    if (r != hole[0] || c != hole[1]) {
                        r -= dirs[i][0];
                        c -= dirs[i][1];
                        dist--;
                    }
                    if (!visited[r][c]) {
                        string cur_path = cur_point.path + turns[i];
                        min_heap.emplace(r, c, dist, cur_path);
                    }
                }
            }
        }
        return "impossible";
    }
private:
    struct Point {
        int row;
        int col;
        int dist;
        string path;
        Point(int r, int c, int d, string p) {
            row = r;
            col = c;
            dist = d;
            path = p; 
        }
    }; 
    struct cmp {
        bool operator()(const Point &p1, const Point &p2){
            if (p1.dist == p2.dist) {
                return p1.path > p2.path;
            } else {
                return p1.dist > p2.dist;
            }
        }
    }; 
};
