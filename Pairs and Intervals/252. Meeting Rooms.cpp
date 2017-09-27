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
    //sorting pairs, define custom function object
    struct {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start < b.start;
        }
    }CompInterval;

    bool canAttendMeetings(vector<Interval>& intervals) {
    //case base : just define empty vector return true;
        if(intervals.empty()) { return true; }
    //not empty vector, we sort the array first
        sort(intervals.begin(), intervals.end(), CompInterval);

    //pass through the array
        for(int i = 1; i < intervals.size(); i++) {
            //check overlapping?
            if(intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};