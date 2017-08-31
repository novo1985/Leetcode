#include <bits/stdc++.h>
using namespace std;

/* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate
 * number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once. *********/

/* O(nlgn), sort the array first! */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int res;
       sort(nums.begin(), nums.end());
       for(int i = 1; i < nums.size(); i++){
           if(nums[i] == nums[i-1]) { res = nums[i]; break; }
       }
        return res;
    }
};

/* NO modify the array !!!
 * suppose there is a array: [1,2,3,4,5,6] n = 6
 * the nums is [1,3,4,2,1,5,6] has n+1 element!
 * find the mid from [1,2,3,4,5,6] m = 3, count element which smaller than or euqals to m*/

class Solution{
public:
  int findDuplicate(vector<int>& nums){
    int p = 0, r = nums.size()-1;
    while(p < r){
      int m = p + (r-p)/2;
      int count = 0;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= m) { count++;}
      }
      if(count > m){// which means the duplicate must in the [1,..m]
        r = m;
      }
      else{
        p = m+1;
      }
    }
    return p;
  }
};

//O(n)!
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1){
              int slow = nums[0];
              int fast = nums[nums[0]];
              while (slow != fast){
                  slow = nums[slow];
                  fast = nums[nums[fast]];
              }

            fast = 0;
            while (fast != slow){
                  fast = nums[fast];
                  slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }s
};



