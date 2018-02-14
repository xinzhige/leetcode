/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), myfunc);
    vector<Interval> result{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      if (result.back().end < intervals[i].start) {
	      result.emplace_back(intervals[i]);
      } else {
	      result.back().end = max(intervals[i].end, result.back().end);
      }
    }
    return result;
  }

  // Note myfunc should be static because it is not object dependent.
  // And it should compare start not end because it would fail if
  // the intervals is [[1, 4], [0, 4]].
  static bool myfunc(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }
};
