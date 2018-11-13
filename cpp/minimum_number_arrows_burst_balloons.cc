class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    if (points.empty()) {
      return 0;
    }
    sort(points.begin(), points.end(), mycomparator);
    int result = 1;
    int end = points[0].second;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i].first <= end) {
        end = min(end, points[i].second);
      } else {
        result += 1;
        end = points[i].second;
      }
    }
    return result;
  }
private:
  struct Comparator {
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.first < p2.first;
    }
  }mycomparator;
};
