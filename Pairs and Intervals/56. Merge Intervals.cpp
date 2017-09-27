/* Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */



//intervals: step1: sort by start

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> res;
      //cornner case, empty set
      if(intervals.empty()) {
        return res;
      }

      //sorting by start, regular expression
      sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
      });

      //pass through sorted intervals
      for(int i = 0; i < intervals.size(); i++) {
        if(!res.empty() && res.back().end < intervals[i].start) {// no overlaping
          res.push_back(intervals[i]);
        }else if(!res.empty() && res.back().end >= intervals[i].start){//has overlap
          //new coming intervals need to be merged with the back one
          res.back().end = max(res.back().end, intervals[i].end);
        }else {
        res.push_back(intervals[i]);//push
        }
      }
      return res;
    }
};




