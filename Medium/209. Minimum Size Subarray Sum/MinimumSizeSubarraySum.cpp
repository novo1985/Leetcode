#include <bits/stdc++.h>
using namespace std;

/* Given an array of n positive integers and a positive integer s, find the minimal length of a
 * contiguous subarray of which the sum = s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.    *********************/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if(nums.empty()) { return 0; }
      vector<int> len;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] > s) { continue; }
        if(nums[i] == s) { return 1; }
        else{
            int temp = nums[i];
            int j = i;
            while(i+1 < nums.size() && temp < s){
              temp = temp + nums[i+1];
              i++;
            }
            if(temp == s) { len.push_back(i-j+1);}
            i = j;
        }
      }
      if(len.empty()){ return 0;}
      sort(len.begin(), len.end());
      return len[0];
    }
};


// sum >= s
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if(nums.empty()) { return 0;}
      vector<int> len;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= s) { len.push_back(1); }
        else{
          int sum = nums[i];
          int j = i;
          while(i+1 < nums.size() && sum < s){
            sum += nums[i+1];
            i++;
          }
          if(sum >=s ){ len.push_back(i-j+1); }
          i = j;
        }
      }
      if(len.empty()) { return 0; }
      sort(len.begin(), len.end());
      return len[0];
    }
};


class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums) {
    int firstPos = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minLength = min(minLength, i - firstPos + 1);
            sum -= nums[firstPos++]; //key statement!
        }
    }

    return minLength == INT_MAX? 0 : minLength;
  }
};












