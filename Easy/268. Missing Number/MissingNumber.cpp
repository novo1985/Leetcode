#include <iostream>
#include <vector>
using namespace std;

/* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is
 * missing from the array.
 * For example,
 * Given nums = [0, 1, 3] return 2.    ************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      // the default nums should be [0,1,2,3,4 ... n]
      if(nums.size() == 0) {return 0;}
      sort(nums.begin(), nums.end());
      int i = 0;
      while(i < nums.size()){
        if(i != nums[i]){
          return i;
        }
        i++;
      }
      return i;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto &a : nums) {
            sum += a;
        }
        return 0.5 * n * (n + 1) - sum;
    }
};

