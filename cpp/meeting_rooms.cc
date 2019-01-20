class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i - 1].end > intervals[i].start) {
        return false;
      }
    }
    return true;
  }

private:
  class Compare {
  public:
    bool operator() (const Interval & a, const Interval & b) {
      return a.start < b.start;
    }
  }compare;
};
