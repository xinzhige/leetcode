/* Load all intervals to the hashmap, where keys are intervals' start/end
 * and values are +1 for start and -1 for end.
 * Traverse the hashmap (in other words, sweep the timeline).
 * Calculate the number of the active ongoing intervals and the least rooms.
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
