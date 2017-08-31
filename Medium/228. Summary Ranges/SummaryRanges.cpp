#include <bits/stdc++.h>
using namespace std;

/* Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].***********************/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    //string will give the range of array!
      vector<string> res;
      if(nums.empty()) { return res; }
      int start = 0, end = 0; // start and end of a string
      for(int i = 1; i <= nums.size();){ // i = nums.size() corn case!!!
        if(i < nums.size() && nums[i] == nums[end] + 1) { end++; i++;}
        else{
          string s;
          if(nums[start] == nums[end]) { s = to_string(nums[start]); }
          else{ s = to_string(nums[start]) + "->" + to_string(nums[end]); }
          res.push_back(s);
          start = i;
          end = i;
          i++;
        }
      }
      return res;
    }
};







