#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given a collection of intervals, merge all overlapping intervals.
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18]. *************************/

struct Interval{
  int start;
  int end;
  Interval():start(0), end(0){}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
public:
  vector<Interval> merge(vector<Interval>& intervals){
    //can be sorted? sorted by intervals[i]->start?
    vector<Interval> res;
    int n = intervals.size();
    mergesortIntervals(intervals, 0, n-1);
    //for(auto a : intervals){ cout << a << endl; }
    for(int i = 0; i < n; i++){
      if(res.empty() || res.back().end < intervals[i].start){ // no overlap
        res.push_back(intervals[i]);
      }else{
        /* has over lap, due to sorted, the last elment of res : [6, 11]
         * intervals[i] = [7, 9], it doesnot need to add new intervals into
         * res, only update the last element of res (->end) ******/
        res.back().end = max(res.back().end, intervals[i].end);
      }
    }
    return res;
  }

  void mergetogether(vector<Interval>& intervals, int p, int q, int r){
    int n1 = q - p + 1; // length of new vector one
    int n2 = r - q; // lenght of new vector two
    vector<Interval> L (n1, Interval());
    vector<Interval> R (n2, Interval());
    // assign values
    for(int i = 0; i < n1; i++){
      L[i].start = intervals[p+i].start;
      L[i].end = intervals[p+i].end;
    }
    for(int j = 0; j < n2; j++){
      R[j].start = intervals[q+j+1].start;
      R[j].end = intervals[q+j+1].end;
    }
    int i = 0, j = 0;
    for(int k = 0; k < r-p+1; k++){
      if(L[i].start <= R[j].start){
        intervals[k] = L[i];
        i++;
      }else{
        intervals[k] = R[j];
        j++;
      }
    }
  }

  void mergesortIntervals(vector<Interval>& intervals, int start, int end){ // merge sort
    int p = start, r = end;
    if(p < r){
      int q = p + (r-p)/2;
      mergesortIntervals(intervals, p, q);
      mergesortIntervals(intervals, q+1, r);
      mergetogether(intervals, p, q, r);
    }
  }
};

//sort function
class Solution {
public:
    struct compInterval {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start<b.start;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compInterval());
        int n = intervals.size();
        for(int i = 0; i < n; i++){
          if(res.empty() || res.back().end < intervals[i].start){ // no overlap
            res.push_back(intervals[i]);
          }else{
        /* has over lap, due to sorted, the last elment of res : [6, 11]
         * intervals[i] = [7, 9], it doesnot need to add new intervals into
         * res, only update the last element of res (->end) ******/
            res.back().end = max(res.back().end, intervals[i].end);
          }
        }
          return res;
    }

};









