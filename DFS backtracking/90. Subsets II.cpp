/* Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.*/

//solution1: dfs backtracking, and remove duplicate by two methods
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;
      //method1: sorting and heaping
      sort(nums.begin(), nums.end());//nlogn
      dfs(0, nums, sol, res);//start at index = 0;
      return res;
    }
    void dfs(int start, vector<int>& nums, vector<int>& sol, vector<vector<int>>& res) {
      //return condition, add all possible solutions
      res.push_back(sol);

      if(start >= nums.size()) { return; }

      for(int i = start; i < nums.size(); i++) {
        //heaping to remove duplicate
        if(i > start && nums[i] == nums[i-1]) { continue; }
        sol.push_back(nums[i]);
        dfs(i+1, nums, sol, res);
        sol.pop_back();//backtracking
      }
    }
};


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;
      //method2: using set, do not need sorting
      //sort(nums.begin(), nums.end());//nlogn
      dfs(0, nums, sol, res);//start at index = 0;
      return res;
    }
    void dfs(int start, vector<int>& nums, vector<int>& sol, vector<vector<int>>& res) {
      //return condition, add all possible solutions
      res.push_back(sol);

      if(start >= nums.size()) { return; }

      set<int> set;//generate set here
      for(int i = start; i < nums.size(); i++) {
        //check the adding element in the set
        if(set.count(nums[i]) == 0) {
          set.insert(nums[i]);
          sol.push_back(nums[i]);
          dfs(i+1, nums, sol, res);
          sol.pop_back();//backtracking
        }
      }
    }
};






