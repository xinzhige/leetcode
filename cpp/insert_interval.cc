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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    Interval tmp = newInterval;
    vector<Interval> result;
    for (auto & curr : intervals) {
      if (tmp.end < intervals[i].start) {
        result.push_back(tmp);
        tmp = intervals[i];
      } else if (intervals[i].end < temp.start) {
        result.push_back(intervals[i]);
      } else {
        tmp.start = min(tmp.start, intervals[i].start);
        tmp.end = max(tmp.end, intervals[i].end);
      }
    }
    result.push_back(temp);
    return result;
  }
};
