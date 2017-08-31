#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Given an array S of n integers, find three integers in S such that the sum is closest
 * to a given number, target. Return the sum of the three integers. You may assume that each
 * input would have exactly one solution.    ***************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int start = 0, end = 0;
      int min_diff = INT_MAX;

      for(int k = 0; k < n - 2; k++){
        start = k+1, end = n-1;
        int reminder = target - nums[k];
        int two_sum = nums[start] + nums[end];
        while(start < end){
          if(abs(two_sum - reminder) < abs(min_diff)) { min_diff = two_sum - reminder;}
          if(two_sum - reminder == 0){
            break;
          }
          else if (two_sum - reminder < 0){
            start++;
          }
          else{
            end--;
          }
        }
      }
      return target + min_diff;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3) return INT_MAX;
        sort(num.begin(),num.end());
        int minDiff = INT_MAX;
        for(int i=0; i<num.size()-2; i++) {
            int left=i+1, right = num.size()-1;
            while(left<right) {
                int diff = num[i]+num[left]+num[right]-target;
                if(abs(diff)<abs(minDiff)) minDiff = diff;
                if(diff==0)
                    break;
                else if(diff<0)
                    left++;
                else
                    right--;
            }
        }
        return target+minDiff;
    }
};