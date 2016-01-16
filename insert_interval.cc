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
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    Interval temp = newInterval;
    vector<Interval> v;
    for(int i = 0; i < intervals.size(); i++) {
      if(intervals[i].start > temp.end) {   // temp is before current
	v.push_back(temp);
	temp = intervals[i];
      } else if (intervals[i].end < temp.start) {  // temp is after current
	v.push_back(intervals[i]);
      } else {                                     // overlap
	temp.start = min(temp.start, intervals[i].start);
	temp.end = max(temp.end, intervals[i].end);
      }
    }
    v.push_back(temp);
    return v;
  }
};
