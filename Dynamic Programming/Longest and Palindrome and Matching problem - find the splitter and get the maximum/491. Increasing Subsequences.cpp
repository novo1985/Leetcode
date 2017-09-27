/* Given an integer array, your task is to find all the different possible increasing subsequences
 * of the given array, and the length of an increasing subsequence should be at least 2 .*/

/* using backtracking! */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;//one acceptable solution
      dfs(0, sol, nums, res);
      return res;
    }

    void dfs(int start, vector<int>& sol, vector<int>& nums, vector<vector<int>>& res) {
      //stop condition: start >= nums.size()!
      if(start >= nums.size()) { return; }

      //acceptable sol
      //if(sol.size() >= 2) { res.push_back(sol); }

      //dfs backtracking
      set<int> s;
      for(int i = start; i < nums.size(); i++) {
        if(i > start && s.find(nums[i]) != s.end()) { continue; }//unsorted!! only using set to check duplicate
        if(sol.empty() || nums[i] >= sol.back()) {
            s.insert(nums[i]);
            sol.push_back(nums[i]);
            //acceptable sol
            if(sol.size() >= 2) { res.push_back(sol); }
            dfs(i+1, sol, nums, res);
            sol.pop_back();
        }
      }
    }
};



