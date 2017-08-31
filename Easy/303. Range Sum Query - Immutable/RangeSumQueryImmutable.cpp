#include <iostream>
#include <vector>
using namespace std;

/* Given an integer array nums, find the sum of the elements between
 * indices i and j (i ≤ j), inclusive.    *************/

// Dynamic Programming: define Sum[i] as sum of array ending with nums[i]!
class NumArray {
public:
    NumArray(vector<int> nums)
      : Sum(nums.size(), 0) {
      //Sum.resize(nums.size());
      if(!Sum.empty()) {
        Sum.at(0) = nums[0];
        for(int i = 1; i < nums.size(); i++){
            Sum[i] = Sum[i-1] + nums[i];
        }
      }
    }

    int sumRange(int i, int j) {
        if (Sum.empty()) { return 0; }
        return  i == 0? Sum[j] : Sum[j] - Sum[i-1];
    }
private:
  vector<int> Sum;
};