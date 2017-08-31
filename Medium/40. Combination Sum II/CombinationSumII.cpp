#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given a collection of candidate numbers (C) and a target number (T), find all unique combinations
 * in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]*******************************/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> sol;
      if(candidates.empty()) { return res; }
      sort(candidates.begin(), candidates.end());
      findnumber(candidates, 0, target, sol, res);
      return res;
    }

    void findnumber(vector<int>& candidates, int start, int target, vector<int>& sol,
                      vector<vector<int>>& res){
      if(target == 0){
        res.push_back(sol);
        return;
      }
      for(int i = start; i < candidates.size(); i++){
        if(i > start && candidates[i] == candidates[i-1]) { continue; } // remove duplicates
        if(candidates[i] <= target){
          sol.push_back(candidates[i]);
          findnumber(candidates, i+1, target - candidates[i], sol, res); // only difference is "i+1"
          sol.pop_back();
        }
      }
    }
};


