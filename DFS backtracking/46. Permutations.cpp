/* Given a collection of distinct numbers, return all possible permutations.*/

//DFS backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;
      if(nums.empty()) { return res; }
      vector<bool> visited(nums.size(), false);
      dfs(visited, nums, sol, res);
      return res;
    }

    void dfs(vector<bool>& visited, vector<int>& nums, vector<int>&sol,
     vector<vector<int>>& res) {
      //DFS backtracking stop/return condition
      if(sol.size() == nums.size()) { res.push_back(sol); return;}//one permutation sequence

      for(int i = 0; i < nums.size(); i++) {
        if(visited[i]) { continue; }
        visited[i] = true;
        sol.push_back(nums[i]);
        dfs(visited, nums, sol, res);
        sol.pop_back();
        visited[i] = false;
      }
    }
};

//solution: swaping!
//finish each slot (_, _, _, .. ,_) slot where index = 0, has n possiblities, implemented by swap
//slot where index = 1, has n-1 possiblities.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      //swaping does not need extra space;
      dfs(nums, 0, res);
      return res;
    }
    void dfs(vector<int>& nums, int index, vector<vector<int>>& res) {
      //backtracking stop/return condition:
      if(index >= nums.size()) {
        res.push_back(nums);
        return;
      }
      //backtracking step, dfs
      for(int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        dfs(nums, index+1, res);
        swap(nums[index], nums[i]);//backtrack
      }
    }
};
















