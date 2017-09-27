/* input: ascending attack time points array && poison duration time
 * output: total time of poison duration */

/* it looks like a lot of intervals : {timeSeries[i], timeSeries[i] + duration -1}
 *  intervals.start = timeSeries[i]
 *  intervals.end = timeSeries[i] + duration - 1;
 * output: merge all overlap intervals, and calculate the total length of all merged intervals
 ********/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        //corner case: empty set or duration == 0
        if(timeSeries.empty() || duration <= 0) { return 0; }

        //timeSeries is ascending order! Just as Intervals sorted by start time
        int start = timeSeries[0], end = timeSeries[0] + duration - 1;
        for(int i = 1; i < timeSeries.size(); i++) {
          if(timeSeries[i] <= end) {//overlap
            end = timeSeries[i] + duration - 1;
          } else {
            res += end - start + 1;
            start = timeSeries[i];
            end = timeSeries[i] + duration - 1;
          }
        }
        res += end - start + 1;

        return res;
    }
};