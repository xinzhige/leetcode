// Idea: compare each element with new interval, if overlapping, then make a
// new interval with minimum start and maximum end of them. Otherwise, put
// either of them into the result.
class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    Interval tmp = newInterval;
    vector<Interval> result;
    for (const auto& curr : intervals) {
      if (tmp.end < curr.start) {
        result.push_back(tmp);
        tmp = curr;
      } else if (curr.end < tmp.start) {
        result.push_back(curr);
      } else {
        tmp.start = min(tmp.start, curr.start);
        tmp.end = max(tmp.end, curr.end);
      }
    }
    result.push_back(tmp);
    return result;
  }
};
