/* Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all
 * unique combinations in C where the candidate numbers sums to T.

 * The same repeated number may be chosen from C unlimited number of times.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
***************/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> sol;
      //sorting array
      sort(candidates.begin(), candidates.end());
      dfs(0, target, candidates, sol, res);
      return res;
    }

    void dfs(int start, int target, vector<int>& candidates, vector<int>& sol,
         vector<vector<int>>& res) {
      //Backtracking return condition: target == 0
        if(target == 0){
          res.push_back(sol);
          return;
        }
      //stop condition: target < 0
        if(target < 0) { return; }

      //DFS recursion:
        for(int i = start; i < candidates.size(); i++) {
          sol.push_back(candidates[i]);
          dfs(i, target-candidates[i], candidates, sol, res);//can repeat use i
          sol.pop_back();
        }

    }
};























