#include <iostream>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given an array of integers sorted in ascending order, find the starting and ending position
 * of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].

 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].     **************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res (2,-1);
      if(nums.empty()) { return res; }
      return findTarget(nums, 0, nums.size()-1, res, target);

    }
    vector<int> findTarget(vector<int>& nums, int start, int end, vector<int>& res, int target){
      int i = start, j = end;
      while(i <= j){
        int mid = i + (j-i)/2;
        if(nums[mid] == target){
          res[0] = findTarget(nums, i, mid-1, res, target).at[0];
          res[1] = findTarget(nums, mid+1, j, res, target).at[1];
        }else if(nums[mid] > target){
          j = mid - 1;
        }else{
          i = mid + 1;
        }
      }
      return res;
    }
};


//
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    // write your code here
    vector<int> ans;
    int ansl = -1;
    for (int l = 0, r = nums.size() - 1; l <= r;) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      }
      if (nums[mid] < target) {
        l = mid + 1;
      }
      if (nums[mid] == target) {
        ansl = mid;
        r = mid - 1; // find left most
      }
    }

    int ansr = -1;
    for (int l = 0, r = nums.size() - 1; l <= r;) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      }
      if (nums[mid] < target) {
        l = mid + 1;
      }
      if (nums[mid] == target) {
        ansr = mid;
        l = mid + 1; // find right most
      }
    }
    ans.push_back(ansl);
    ans.push_back(ansr);
    return ans;
  }
};





