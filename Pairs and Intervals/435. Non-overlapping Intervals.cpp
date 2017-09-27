/* Given a collection of intervals, find the minimum number of intervals you need to remove
 * to make the rest of the intervals non-overlapping.*/

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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) { return 0; }
        //sort intervals by Interval.start
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
          return a.start < b.start;
        });

        int count = 0;
        int end = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++) {
          if(intervals[i].start < end) {//overlap
            count++;
            end = min(end, intervals[i].end);
          }else {//no overlap
            end = intervals[i].end;
          }
        }
        return count;
    }
};

















