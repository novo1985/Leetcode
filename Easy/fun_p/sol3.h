//
// Created by Lei Gao on 9/28/17.
//

#ifndef FUN_P_SOL3_H
#define FUN_P_SOL3_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution3{
public:
  int maxdif(vector<int>& nums) {
    int maxdiff = 0;
    int min_index = 0;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
      if(nums[i] > nums[min_index]) {
        maxdiff = max(maxdiff, nums[i] - nums[min_index]);
      }
      else{
        min_index = i;
      }
    }

    return maxdiff;
  }
};
#endif //FUN_P_SOL3_H
