#include <bits/stdc++.h>
using namespace std;

/* Given an array with n objects colored red, white or blue, sort them so that objects of the
 * same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.  *************************/

class Solution {
public:
    void sortColors(vector<int>& nums) {
      //no sort function! [1,1,2,1,2,0,0,2,0] --> [0,0,0,1,1,1,2,2,2]
      /*like three way partition, use three index: left which point to last 0
                                                   cur which point to last 1
                                                   right which point to first 2*/
      int n = nums.size()-1;
      int left = 0, right = n-1, cur = 0;
      while(cur <= right){
        if(nums[cur] == 0){
          swap(nums[cur], nums[left]);
          cur++;
          left++;
        }
        else if(nums[cur] == 1){
          cur++;
        }
        else{
          swap(nums[cur], nums[right]);
          right--;
        }
      }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n = nums.size();
      int left = 0, right = n-1, cur = 0;
      for(cur = 0; cur <= right;){
        if(nums[cur] == 0){
          swap(nums[cur], nums[left]);
          cur++;
          left++;
        }
        else if(nums[cur] == 1){
          cur++;
        }
        else{
          swap(nums[cur], nums[right]);
          right--;
        }
      }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        int i = 0;
        while(i<=right) {
            if(nums[i]==0)
                swap(nums[i++],nums[left++]);
            else if(nums[i]==1)
                i++;
            else if(nums[i]==2)
                swap(nums[i],nums[right--]);
        }
    }
};
















