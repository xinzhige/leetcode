class Solution {
public:
  int maxPoints(vector<Point> &points) {
    int num_points = points.size();
    if (num_points < 3) return num_points;
    int result = 0;
    int count = 0; // store current count of points with the same slope
    unordered_map<double, int> slope_count;
    for (int i = 0; i < num_points - 1; ++i) {
      slope_count.clear();
      int samePointNum = 0;
      int point_max = 1; 
      for (int j = i + 1; j < num_points; ++j) { 
	double slope; 
	if (points[i].x == points[j].x) {
	  slope = std::numeric_limits<double>::infinity();
	  if (points[i].y == points[j].y) {
	    ++ samePointNum;
	    continue; 
	  }
	} else {
	  slope = 1.0 * (points[i].y - points[j].y) /
	    (points[i].x - points[j].x);
	}
	if (slope_count.find(slope) != slope_count.end()) {
	  ++slope_count[slope];
	  count = slope_count[slope];
	} else {
	  count = 2;
	  slope_count[slope] = 2;
	}
	point_max = max(point_max, count);
      }
      result = max(result, point_max + samePointNum);
    }
    return result;
  }
};
