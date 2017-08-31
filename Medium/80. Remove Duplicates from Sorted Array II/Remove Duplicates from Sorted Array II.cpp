#include <bits/stdc++.h>
using namespace std;

/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. ***********/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      vector<int> v;
      int n = nums.size();
      if(n < 3) { return n; }
      int end = 0;
      for(int i = 1; i < nums.size(); i++){
        if( nums[end] != nums[i]){
          end++;
          if( end != i ){ nums[end] = nums[i]; }
        }
        else{
          int temp = nums[end];
          while(nums[i] == nums[end] && i < nums.size()){
              i++;
          }
          if(nums[i] == nums[end]){
            end++;
          }else{
          end += 2;
          nums[end-1] = temp;
          nums[end] = nums[i];
          }
        }
      }
      return end+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int end = 1;
        for(int i=2; i<n; i++) {
            if(nums[i]!=nums[end-1]) { nums[++end] = nums[i]; }
        }
        return end+1;
    }
};
/* Remove Duplicates from Sorted Array I
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if(n < 2 ) { return n;}
      int new_end = 0;
      for(int i = 1; i < n; i++){
        if(nums[i] != nums[new_end]){
          new_end++;
          if(new_end != i){ nums[new_end] = nums[i]; }
        }
      }
      return new_end+1;
    }
};
*/






