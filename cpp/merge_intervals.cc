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
    if (intervals.size() == 0) {
      return intervals; 
    }
    sort(intervals.begin(), intervals.end(), myfunc);
    vector<Interval> result{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start <= result.back().end) {
	result.back().end = max(intervals[i].end, result.back().end); 
      } else {
	result.emplace_back(intervals[i]); 
      } 
    }
    return result;
  }

private:
  class Compare {
  public:
    bool operator() (const Interval& a, const Interval& b) {
      return a.start < b.start; 
    }        
  }mycompare;
};
