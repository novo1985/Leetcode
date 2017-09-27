/* Given a collection of candidate numbers (C) and a target number (T), find all unique
 * combinations in C where the candidate numbers sums to T.

 * Each number in C may only be used once in the combination.

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> res;//return value
      vector<int> sol; //one accepted solution
      //sorting to calculate sum/target
      sort(candidates.begin(), candidates.end());
      dfs(0, target, candidates, sol, res);
      return res;
    }

    void dfs(int start, int target, vector<int>&candidates, vector<int>& sol,
      vector<vector<int>>& res) {
      //stop condition: target < 0
      if(target < 0) { return; }//go back, backtracking

      //adding condition: target == 0, one accepted solution
      if(target == 0) {
        res.push_back(sol);
        return;
      }

      //DFS recursion, numbers can not be repeadly used
      for(int i = start; i < candidates.size(); i++) {
        //remove repeated starting point
        if(i > start && candidates[i] == candidates[i-1]) { continue; }
        sol.push_back(candidates[i]);
        dfs(i+1, target - candidates[i], candidates, sol, res);
        sol.pop_back();
      }
    }
};














