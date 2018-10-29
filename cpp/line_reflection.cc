class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int, set<int>> mymap;
    int max_x = INT_MIN;
    int min_x = INT_MAX;
    for (const auto &p : points) {
      max_x = max(max_x, p.first);
      min_x = min(min_x, p.first);
      mymap[p.first].insert(p.second);
    }
    int y = max_x + min_x;
    for (const auto &p : points) {
      int t = y - p.first;
      if (mymap.count(t) == 0 || mymap[t].count(p.second) == 0) {
        return false;
      }
    }
    return true;
  }
};
