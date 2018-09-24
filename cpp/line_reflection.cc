class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    if (points.size() == 0 || points.size() == 1) {
      return true;
    }
    int left = INT_MAX;
    int right = INT_MIN;
    unordered_map<int, set<int>> mymap;
    for (const auto &p : points) {
      left = min(left, p.first);
      right = max(right, p.first);
      mymap[p.second].insert(p.first);
    }
    double line = (left + right) / 2.0;
    for (auto it = mymap.begin(); it != mymap.end(); ++it) {
      auto currSet = it->second;
      auto start = currSet.begin();
      auto end = currSet.end();
      for (; start != end; ++start) {
        end -= 1;
        if ((*start + *end) / 2.0 != line) {
          return false;
        }
        if (start == end) {
          break;
        }
      }
    }
    return true;
  }
};
