/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/* Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].*/

/* sort these intervals first, we need overriding operation of sorting*/

/*     // sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {
            return a < b;
        }
    } customLess;*/


class Solution {
public:
    //sorting using a custom function object
    struct CompInterval {
      bool operator() (const Interval &a, const Interval &b) const{
        return a.start < b.start;
      }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
      //base case: empty
      vector<Interval> res;
      if(intervals.empty()) { return res; }
      //if not, sort the Interval array
      sort(intervals.begin(), intervals.end(), CompInterval);

      //pass through the vector
      for(int i = 0; i < intervals.size(); i++) {
        if(res.empty() || res.back().end < intervals[i].start) {//beginning or no overlap
            res.push_back(intervals[i]);
        }else {//has overlapping: merge new coming with the end Interval, no increased member in vector
          //already sort by start, we need update Interval.end
          res.back().end = max(res.back().end, intervals[i].end);
        }
      }
      return res;
    }
};