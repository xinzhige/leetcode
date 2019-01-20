// Note: if i starts from 0 and intervals size is 0, then it can not
// deduct 1 from intervals.size() because intervals.size() is unsigned
// and it causes overflow.
class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i - 1].end > intervals[i].start) {
        return false;
      }
    }
    return true;
  }

private:
  class Comparison {
  public:
    bool operator() (const Interval & a, const Interval & b) {
      return a.start < b.start;
    }
  }comp;
};
