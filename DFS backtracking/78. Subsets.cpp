/* Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.*/

//solution1: DFS backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //distinct integers
        vector<vector<int>> res;
        vector<int> sol;
        dfs(0, nums, sol, res);
        return res;
    }

    void dfs(int start, vector<int>&nums, vector<int>& sol, vector<vector<int>>& res) {
      //empty subset!
      res.push_back(sol);//add each possible subset

      if(start >= nums.size()) { return; }
      //DFS backtracking, add element by index
      for(int i = start; i < nums.size(); i++) {
        sol.push_back(nums[i]);
        dfs(i+1, nums, sol, res);//why i+1 ?  not start+1?
        sol.pop_back();//backtracking
      }
    }
};

//solution2: iteration
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //initailization: res = [[]];
        vector<vector<int>> res(1, vector<int>());
        for(int i = 0; i < nums.size(); i++) {
          int len = res.size();
          for(int j = 0; j < len; j++) {//copy and paste
            res.push_back(res[j]);//copy index j
            res.back().push_back(nums[i]);//paste
          }
        }
        return res;
    }
};



