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
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), mycomparison);
    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (result.back().end < intervals[i].start) {
	      result.emplace_back(intervals[i]);
      } else {
	      result.back().end = max(intervals[i].end, result.back().end);
      }
    }
    return result;
  }

  struct Comparison {
    bool operator() (const Interval& a, const Interval& b) {
      return a.start < b.start;
    }
  }mycomparison;
};
