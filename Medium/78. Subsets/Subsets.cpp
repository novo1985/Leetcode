#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets. */

//method1: backtracking--recursively call function
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> TotalSubset;
        vector<int> temp;
        backtrack(TotalSubset, temp, nums, 0);
        return TotalSubset;
    }
    void backtrack(vector<vector<int>>& TotalSubset, vector<int>& temp,
     vector<int>& nums, int start){
      TotalSubset.push_back(temp);
      for(int i = start; i < nums.size();i++){
        temp.push_back(nums[i]);
        backtrack(TotalSubset, temp, nums, i+1);
        temp.pop_back();
      }
    }
};

//method2: non-recursive
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> temp;
      res.push_back(temp);

      for(int i = 0; i < nums.size(); i++){
        int k = res.size();
        for(int j = 0; j < k; j++){
          vector<int> list = res[j];
          list.push_back(nums[i]);
          res.emplace_back(move(list));
        }
      }
      return res;
    }
};













