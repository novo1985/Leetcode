#include <iostream>
#include <vector>
//#include <algorithm>
//#include <unordered_map>
using namespace std;

/* Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed? Would this affect the run-time complexity? How and why?
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Write a function to determine if a given target is in the array.
 * The array may contain duplicates.                                         *********************/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
          int m = i + (j-i)/2;
          if(nums[m] == target) { return true;}
          else if( nums[m] > nums[j]){ // left side is sorted!
            if(target >= nums[i] && target < nums[m]){
              j = m-1;
            }
            else{
              i = m+1;
            }
          }
          else if (nums[m] < nums[j]){ // nums[m] < nums[j] , right side is sorted!
            if(target > nums[m] && target <= nums[j]){
              i = m + 1;
            }else{
              j = m-1;
            }
          }
          else{ // nums[m] == nums[j], both side possible, only rule out end
            j--;
          }
        }
        return false;
    }
};





