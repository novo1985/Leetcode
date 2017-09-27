/* Given a set of non-overlapping intervals, insert a new interval into the intervals
 * (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times. */

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> res;
      if(intervals.empty()) {
        res.push_back(newInterval);
        return res;
      }
      //intervals already sorted by start
      //find the first Interval of which end less than newInterval.start

      int start = 0, end = 0;//index of array
      for(int i = 0; i < intervals.size(); i++) {
        if(intervals[i].end > newInterval.start)
      }
    }
};










