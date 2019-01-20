/* Load all intervals to the TreeMap, where keys are intervals' start/end
 *  boundaries, and values accumulate the changes at that point in time.
 * Traverse the TreeMap (in other words, sweep the timeline). If a new
 * interval starts, increase the counter (k value) by 1, and the counter
 * decreases by 1, if an interval has finished.
 * Calculate the number of the active ongoing intervals.
*/
class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> changes;
    for (const auto &i : intervals) {
      changes[i.start] += 1;
      changes[i.end] -= 1;
    }
    int rooms = 0;
    int result = 0;
    for (const auto &c : changes) {
      rooms += c.second;
      result = max(result, rooms);
    }
    return result;
  }
};


// Heap
class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto &i : intervals) {
      if (!pq.empty() && pq.top() <= i.start) {
        pq.pop();
      }
      pq.push(i.end);
    }
    return pq.size();
  }

private:
  struct Comparison {
    bool operator() (const Interval& a, const Interval& b) {
      return a.start < b.start;
    }
  }comp;
};
