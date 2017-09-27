/* Given an integer array with all positive numbers and no duplicates, find
 * the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7. ********************************************/

//backtracking: numbers can be repeadly used! no length limitation, memory limited!!!!
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      vector<vector<int>> res;//store all acceptable combinations
      vector<int> sol;//one acceptable combinations
      //sorting array
      sort(nums.begin(), nums.end());
      dfs(0, target, nums, sol, res);
      return res.size();
    }

    void dfs(int start, int target, vector<int>& nums, vector<int>& sol, vector<vector<int>>& res) {
      //backtracking adding solution condition: target == 0
      if(target == 0) {
        res.push_back(sol);
        return;
      }
      //backtracking stoping condition, go back then searching: target < 0
      if(target < 0) { return; }

      //DFS recursion:
      for(int i = 0; i < nums.size(); i++) {//each starting point searching from i == 0!
        sol.push_back(nums[i]);
        dfs(start+1, target - nums[i], nums, sol, res);
        sol.pop_back();
      }
    }
};

//just return count! time limited!!!
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      //vector<vector<int>> res;//store all acceptable combinations
      //vector<int> sol;//one acceptable combinations
      //sorting array
      sort(nums.begin(), nums.end());
      int count = 0;
      dfs(0, count, target, nums);
      return count;
    }

    void dfs(int start, int& count, int& target, vector<int>& nums) {
      //backtracking adding solution condition: target == 0
      if(target == 0) {
        count++;
        return;
      }
      //backtracking stoping condition, go back then searching: target < 0
      if(target < 0) { return; }

      //DFS recursion:
      for(int i = 0; i < nums.size(); i++) {//each starting point searching from i == 0!
        target = target - nums[i];
        dfs(start+1, count, target, nums);
        target = target + nums[i];
      }
    }
};

//DP solution!!!!
/* dp[i]: denote as "the number of subsets of which the sum is i "
 * base case dp[0] = 1; empty subset
 * dp[i] = dp[i - nums[0]] + dp[i - nums[1]] + ... + dp[i - nums[j]]
 *          where i - nums[j] >= 0 ********/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);//dp[0] = 1
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
          for(int j = 0; j < nums.size(); j++) {
            if(i >= nums[j]){
              dp[i] += dp[i - nums[j]];
            }
          }
        }
        return dp[target];
    }
};



















