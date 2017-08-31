#include <bits/stdc++.h>
using namespace std;

/* Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]***************************************/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      if(nums.empty()) { return res; }
      vector<int> out;
      vector<bool> used(nums.size(), false);
      dfs(nums, used, out, res);
      return res;
    }
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& out, vector<vector<int>> res){
      if(out.size() == nums.size()) {
        res.push_back(out);
        return;
      }
      for(int i = 0; i < nums.size(); i++){
        if(used[i] == true) { continue; }
        used[i] = true;
        out.push_back(nums[i]);
        dfs(nums, used, out, res);
        out.pop_back();
        used[i] = false;
      }
    }
};












