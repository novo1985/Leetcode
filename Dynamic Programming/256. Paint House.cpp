/* 1. The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
 * 2. The cost of painting each house with a certain color is different.
 * 3. You have to paint all the houses such that no two adjacent houses have the same color. ******/


/* solution: Dp, there are three start points, cost[0,0], cost[0,1] and cost[0,2]
 *           for each other house, there are three - 1 choices
 *
 * Try1: Let denote sum[0,i] as painting first house with color "i" min cost;
 *
 *
 *
 *
 * Try2: Let denote vector<int> res(3, 0), there are three choice for each start point**********/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
      if(costs.empty() || costs[0].empty()) { return 0; }
      vector<int> res = dfs(0, costs);
      return min(min(res[0], res[1]), res[2]);
    }

    vector<int> dfs(int start, vector<vector<int>>& costs) {
      vector<int> res(3, 0);
      if(start >= costs.size()) { return; }

      vector<int> res(3, 0);
      vector<int> next = dfs(start+1, costs);
      res[0] = costs[start][0] + min(next[1], next[2]);
      res[1] = costs[start][1] + min(next[0], next[2]);
      res[2] = costs[start][2] + min(next[0], next[1]);
      return res;
    }
};