#include <bits/stdc++.h>
using namespace std;

/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.************/

//binary search o(log(n))
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i < j){
          int m = i + (j-i)/2;
          if(nums[m] < nums[j]){ // subarray : [m, .. , j] is sorted
                                 //Min = min(nums[m], findMin([i,.. m-1])) = findMin([i,.. m])
            j = m;
          }else{//subarray: [i, .. m] is sorted, all greater than nums[j], Min = findMin([m+1,..,j])
            i = m+1;
          }
        }
      return nums[i];
    }
};


// o(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }
        return min;
    }
};





