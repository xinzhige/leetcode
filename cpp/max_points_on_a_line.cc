class Solution {
public:
  int maxPoints(vector<Point> &points) {
    int result = 0;
    for (int i = 0; i < points.size(); ++i) {
      map<pair<int, int>, int> slop;
      int count = 1;
      for (int j = i + 1; j < points.size(); ++j) {
        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          count += 1;
        } else {
          int dx = points[i].x - points[j].x;
          int dy = points[i].y - points[j].y;
          int d = gcd(dx, dy);
          slop[{dx / d, dy / d}] += 1;
        }
      }
      result = max(result, count);
      for (auto it = slop.begin(); it != slop.end(); ++it) {
        result = max(result, it->second + count);
      }
    }
    return result;
  }

  int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
  }
};
