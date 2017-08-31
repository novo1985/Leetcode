#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all
 * unique combinations in C where the candidate numbers sums to T.

 * The same repeated number may be chosen from C unlimited number of times.

* Note:
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

* For example, given candidate set [2, 3, 6, 7] and target 7,
* A solution set is:
  [
    [7],
    [2, 2, 3]
  ]                          ************************************/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      //sort, find the index of which value is equal to or bigger than target
      vector<vector<int>> res;
      vector<int> sol;
      if(candidates.empty()) { return res; }
      sort(candidates.begin(), candidates.end());
      findnumber(candidates, 0, target, res, sol);
      return res;
    }
    void findnumber(vector<int>& candidates, int start, int target, vector<vector<int>>& res,
                      vector<int>& sol){
      if(target == 0) { res.push_back(sol); return; }
      for(int i = start; i < candidates.size(); i++){
        if(i > start && candidates[i] == candidates[i-1]) { continue; }
        if(candidates[i] <= target){
          sol.push_back(candidates[i]);
          findnumber(candidates, i, target-candidates[i], res, sol);
          sol.pop_back();
        }
      }
    }
};


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(),candidates.end());
        findCombSum(candidates, 0, target, sol, allSol);
        return allSol;
    }

    void findCombSum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int>> &allSol) {
        if(target==0) {
            allSol.push_back(sol);
            return;
        }

        for(int i=start; i<candidates.size(); i++) {
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target) {
                sol.push_back(candidates[i]);
                findCombSum(candidates, i, target-candidates[i], sol, allSol);
                sol.pop_back();
            }
        }
    }
};
















