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
  int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> mymap;
    for (const auto &a : intervals) {
      mymap[a.start] += 1;
      mymap[a.end] -= 1;
    }
    int rooms = 0;
    int result = 0;
    for (const auto &it : mymap) {
      rooms += it.second; 
      result = max(result, rooms);
    }
    return result;
  }
};


// Heap
class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), mycompare);
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto i : intervals) {
      if (!q.empty() && q.top() <= i.start) {
	q.pop(); 
      } 
      q.emplace(i.end);
    }
    return q.size();
  }

private:
  struct Compare {
    bool operator() (const Interval& a, const Interval& b) {
        return a.start < b.start; 
    }
  }mycompare;
};
