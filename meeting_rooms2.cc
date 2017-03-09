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
        vector<int> mystart, myend;
        for (auto i : intervals) {
            mystart.emplace_back(i.start); 
            myend.emplace_back(i.end);
        }
        sort(mystart.begin(), mystart.end());
        sort(myend.begin(), myend.end());
        int result = 0;
        int end_pos = 0;
        for (int i = 0; i < mystart.size(); ++i) {
            if (mystart[i] < myend[end_pos]) {
                result += 1; 
            } else {
                end_pos += 1; 
            } 
        }
        return result;
    }
};


// Heap
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
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
    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start; 
    }
};
