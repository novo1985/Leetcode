#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Given an array of integers and an integer k, find out whether there are two distinct indices
 * i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j
 * is at most k.                                                            ********************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      for(int i = 0; i < nums.size(); i++){
        int j = i+1;
        while(j-i <= k && j < nums.size()){
          if(nums[i] == nums[j]){
            return true;
          }
          j++;
        }
      }
      return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};








