// If n points have the same distance to point i, then there are
// n(n-1) boomerangs with i as the first element.
class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int result = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int> mymap;
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        int dist = distance(points[i], points[j]);
        mymap[dist] += 1;
      }
      for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        result += it->second * (it->second - 1);
      }
    }
    return result;
  }

  int distance(const pair<int, int> &x, const pair<int, int> &y) {
    int dx = x.first - y.first;
    int dy = x.second - y.second;
    return dx * dx + dy * dy;
  }
};
