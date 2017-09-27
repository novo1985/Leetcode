/*overlap meeting need different room! */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) { return 0; }
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
          return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> q; // min-heap, store ending time
        for(const auto& it : intervals) {
          if(!q.empty() && q.top() <= it.start) { //no overlap, no more room needed
            q.pop();
          }
          q.push(it.end);
        }

        return q.size();
    }
};