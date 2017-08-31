#include <iostream>
#include <vector>
//#include <algorithm>
//#include <unordered_map>
using namespace std;


/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.*/


//method 1: find the position of pivot O(n), it will form two sorted subarray, then binary search for
//          each subarray.
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if(nums.empty()){ return -1;}
      int n = nums.size();
      int res;
      if(n==1) { return res = nums[0] == target ?  0 : -1;}

      int pivot = 0;
      for(int i = 0;i < nums.size()-1; i++){
        if( nums[i+1] < nums[i]){
          pivot = i;
          break;
        }
          pivot = nums.size()-2;
      }

        //int pivot = i-1;
        cout << "pivot index is " << pivot << endl;

      int res1 = binarySearch(nums, target, 0, pivot);
        cout << "res1 value is " << res1 << endl;

      if(res1 != -1) { return res1; }
      int res2 = binarySearch(nums, target, pivot+1, nums.size()-1);
        cout << "res2 value is " << res2 << endl;
      return res2;
    }

    int binarySearch(vector<int>& nums, int target, int start, int end){
      int i = start, j = end;
      if(i == j && nums[i] == target){ return i; }
      while(i < j){
        int mid = i + (j-i)/2;
        if(nums[mid] == target){
          return mid;
        }else if (nums[mid] > target){
          j = mid - 1;
        }else{
          i = mid + 1;
        }
      }
      int res;
      return res = nums[i] == target? i : -1;
    }
};

//method 2: log(n) recursive

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRotatedSortednumsrray(nums, 0, nums.size()-1, target);
    }

    int searchRotatedSortednumsrray(vector<int>& nums, int start, int end, int target) {
        if(start>end) return -1;
        int mid = start + (end-start)/2;
        if(nums[mid]==target) return mid;

        if(nums[mid]<nums[end]) { // right half sorted
            if(target>nums[mid] && target<=nums[end])
                return searchRotatedSortednumsrray(nums, mid+1, end, target);
            else
                return searchRotatedSortednumsrray(nums, start, mid-1, target);
        }
        else {  // left half sorted
            if(target>=nums[start] && target<nums[mid])
                return searchRotatedSortednumsrray(nums, start, mid-1, target);
            else
                return searchRotatedSortednumsrray(nums, mid+1, end, target);
        }
    }
};

//method 3: iteration
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) { return -1; }
        int i = 0, j = nums.size()-1;
        while(i <= j){
          int m = i + (j-i)/2;
          if(nums[m] == target) { return m;}
          else if( nums[m] > nums[j]){ // left side is sorted!
            if(target >= nums[i] && target < nums[m]){
              j = m-1;
            }
            else{
              i = m+1;
            }
          }
          else{ // nums[m] < nums[j] , right side is sorted!
            if(target > nums[m] && target <= nums[j]){
              i = m + 1;
            }else{
              j = m-1;
            }
          }
        }
        return -1;
    }
};







