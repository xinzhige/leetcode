// Idea: use a variable to store the current end of intervals.
// Case 1: prev.end <= curr.start
// Case 2: curr.start <= prev.start <= prev.end <= curr.end
// Case 3: prev.start <= curr.start << prev.end <= curr.end
// Key: case 2 & 3, the current interval must be removed to get more range.
class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    sort(intervals.begin(), intervals.end(), mycomparison);
    int end = intervals[0].end;
    int count = 1;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start >= end) {
        end = intervals[i].end;
        count += 1;
      }
    }
    return intervals.size() - count;
  }
  struct Comparison {
    bool operator() (const Interval &a, const Interval &b) {
      return a.end < b.end;
    }
  }mycomparison;
};
