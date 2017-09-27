class Solution {
public:
    //overloading compare function for sorting
    struct {
        bool operator() (const Interval &a, const Interval &b) const {
            return a.start != b.start ? a.start < b.start : a.end < b.end;
        }
    }CompInterval;

    int minMeetingRooms(vector<Interval>& intervals) {
        //corner case: empty input!
        if(intervals.empty()) { return 0; }
        //sorting intervals by custom function
        sort(intervals.begin(), intervals.end(), CompInterval);

        //using priority queue(min-heap)
        priority_queue<int, vector<int>, greater<int>> q;//store interval end time
        for(int i = 0; i < intervals.size(); i++) {
            if(!q.empty() && q.top() <= intervals[i].start) {//these two can be in one room by sequential
                q.pop();//so, pop the one with early ending time;
            }
            q.push(intervals[i].end);
        }
        //# of room == size of q
        return q.size();

    }
};