#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.   *********/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      if(nums.size() < 3) { return res;}
      int n = nums.size();
      sort(nums.begin(), nums.end());
      //iterate from k = 0 -> k = n-3; int start = k+1, end = n-1
      for(int k = 0; k < n-2; k++){
        if (nums[k] > 0) break;
        if (k > 0 && nums[k] == nums[k - 1]) continue;
        int reminder = 0 - nums[k];
        int start = k+1, end = n-1;
        while(start < end){
          if(nums[start] + nums[end] > reminder){
            end--;
          }else if(nums[start] + nums[end] < reminder){
            start++;
          }else{
            res.push_back({nums[k],nums[start],nums[end]});
            while(start < end && nums[start] == nums[start + 1]){ start++;}
            while(start < end && nums[end] == nums[end - 1]){ end--;}
            start++;
            end--;
          }
        }
      }
      return res;
    }
};