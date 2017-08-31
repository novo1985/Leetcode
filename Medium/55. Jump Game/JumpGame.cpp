#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given an array of non-negative integers, you are initially positioned at the first index of
 * the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.   **********************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
      //bool res = false;
      if(nums.empty()) { return false; }
      int n = nums.size();

      for(int i = 0; i <= nums[0]; i++){
        if(indexcanjump(nums, 0, i)){
          return true;
        }
      }
      return false;
    }
    bool indexcanjump(vector<int>& nums, int start, int steps){
      int length = nums.size() - start - 1;
      if(start + steps >= length) { return true; }
      if(start+steps < length){
        start += steps;
        for(int j = 0; j <= nums[start]; j++){
          indexcanjump(nums, start, j);
        }
      }
      return false;
    }
};

// greedy algorithm
class Solution{
public:
  bool canJump(vector<int>& nums){
    int maxindex = 0;
    for(int i = 0; i < nums.size(); i++){
      if(i > maxindex || maxindex >= nums.size()-1) { break; }
      maxindex = max(maxindex, i + nums[i]);
    }

    return maxindex >= (nums.size()-1) ? true : false;
  }
};












