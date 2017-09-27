/* Find all possible combinations of k numbers that add up to a number n, given that only
 * numbers from 1 to 9 can be used and each combination should be a unique set of numbers.*/


//Ak belongs [1, .., 9], combination is a set, no duplicate numbers

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> res;//return value
      vector<int> sol;// one acceptable set, which size is k

      //created a array only containing 1,2,3,4,5,6,7,8,9
      vector<int> nums = {1,2,3,4,5,6,7,8,9};
      dfs(0, k, n, nums, sol, res);
      return res;
    }

    void dfs(int start, int k, int target, vector<int>& nums, vector<int>& sol,
        vector<vector<int>>& res) {
      //backtracking: adding solution condition: sol.size == k && target == 0
      if(sol.size() == k && target == 0) {
        res.push_back(sol);
        return;
      }

      //backtracking: stop condition: sol.size > k || target < 0
      if(sol.size() > k || target < 0) { return; }

      //backtracking DFS recursion:
      for(int i = start; i < nums.size(); i++) {
        //numbers cannot be repeadly used, next index should be i+1!
        sol.push_back(nums[i]);
        dfs(i+1, k, target-nums[i], nums, sol, res);
        sol.pop_back();
      }
    }
};

