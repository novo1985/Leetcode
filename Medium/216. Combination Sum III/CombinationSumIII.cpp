#include <bits/stdc++.h>
using namespace std;

/* Find all possible combinations of k numbers that add up to a number n, given that only
 * numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]   ********************************************************/


/* [1,2,3,4,5,6,7,8,9] pick up k different numbers of which sum equals to n
 * */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> res;
      vector<int> sol;
      vector<int> nums = {1,2,3,4,5,6,7,8,9};
      backtrack(res, sol, nums, 0, k, n);
      return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& sol, vector<int>& nums,
                                                                   int start, int k, int n){
      if(n < 0) { return; }
      if(n == 0 && sol.size() == k){ res.push_back(sol); }
      for(int i = start; i < nums.size(); i++){
        sol.push_back(nums[i]);
        backtrack(res, sol, nums, i+1, k, n-nums[i]);
        sol.pop_back();
      }
    }
};




