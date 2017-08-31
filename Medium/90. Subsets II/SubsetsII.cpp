#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



/* Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]                                                **************************/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> temp;
      res.push_back(temp);
      if(nums.empty()) { return res;}

      unordered_map<int, size_t> t; // key(nums.element), frequency
      for(int i = 0; i < nums.size(); i++){
        t[nums[i]]++;
      }

      for (auto i = t.begin(); i != t.end(); i++) {
        int n = res.size();
        for (auto j = 0; j < n; j++) {
          vector<int> list = res[j];
          for (size_t k = 1; k <= i->second; k++) {
            list.push_back(i->first);
            res.emplace_back(list);
          }
        }
      }
      return res;
    }
};




class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(S.begin(), S.end());
        findSubsetsWithDup(S, 0, sol, allSets);
        return allSets;
    }

    void findSubsetsWithDup(vector<int> &S, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        for(int i=start; i<S.size(); i++) {
            if(i>start && S[i]==S[i-1]) continue;
            sol.push_back(S[i]);
            allSets.push_back(sol);
            findSubsetsWithDup(S, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};


