//Intervals problem, sorting and using min-heap
class Solution {
public:
    struct {
      bool operator()(const pair<int, int>& a, pair<int, int>& b) const {
        return a.first < b.first;
      }
    }CompPair;

    int findMinArrowShots(vector<pair<int, int>>& points) {
        //corner case, empty
      if(points.empty()) { return 0; }

      //sorting pairs by start time
      sort(points.begin(), points.end(), CompPair);

      //priority_queue<int, vector<int>, greater<int>> q;//max-heap, top is the maximum end-value
      //q.push(points[0].second);
      int res = 1;
      int end = points[0].second;
      //a arrow is along x = xi
      for(int i = 1; i < points.size(); i++) {
        if(end >= points[i].first) {//which means these two pairs can be shot by one arrow
            end = min(end, points[i].second);
        } else {
          res++;
          end = points[i].second;
        }
      }
      return res;
    }
};






