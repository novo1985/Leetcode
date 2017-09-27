/* Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations. */

//how to deleted duplicate? traditional backtracking
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;
      vector<bool> visited(nums.size(), false);
      sort(nums.begin(), nums.end());
      dfs(nums, sol, visited, res);
      return res;
    }

    void dfs(vector<int>& nums, vector<int>&sol, vector<bool>& visited, vector<vector<int>>& res) {
      //backtracking stop/return condition
      if(sol.size() == nums.size()) {
        res.push_back(sol);
        return;
      }
      //dfs
      for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == false){
          // previous slot is fixed! and backtracking reset to false!
          continue;
        }
        if(visited[i]){ continue; }
        visited[i] = true;
        sol.push_back(nums[i]);
        dfs(nums, sol, visited, res);
        sol.pop_back();//backtracking
        visited[i] = false;//backtracking
      }
    }
};


//solution2: Backtracking [_, _, .. ,_] slots, swaping
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;//return value
        //sort(nums.begin(), nums.end());
        //unordered_set<vector<int>> set;
        dfs(0, nums, res);//deal with index = 0;
        return res;
    }

    void dfs(int start, vector<int>& nums, vector<vector<int>>& res) {
      //backtracking stop/return condition: index from 0 -> nums.size()
      if(start >= nums.size()) {
        res.push_back(nums);
        return;
      }
      //dfs recursion, how to avoid duplicate here? we need use set
      set<int> set;
      for(int i = start; i < nums.size(); i++) {
        if(set.count(nums[i]) == 0) { //avoid duplicate
        set.insert(nums[i]);
        swap(nums[start], nums[i]);
        dfs(start+1, nums, res);
        swap(nums[start], nums[i]);//backtracking
        }
      }
    }
};













