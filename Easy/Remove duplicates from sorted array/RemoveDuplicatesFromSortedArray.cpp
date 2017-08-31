#include <iostream>
#include <vector>
using namespace std;

/* Remove the duplicated number in a sorted array and return the length
 * for example : [2,2,3,4] -> [2,3,4] return len = 3;
 * in-place, no extraspace */

class Solution{
public:
  int removeDuplicates(vector<int>& nums){
    //double indice, one for old array, one for new array
    if(nums.size() < 2) { return nums.size(); }
    int i = 0;
    for(int j = 1; j < nums.size(); j++){
      if(nums[i] != nums[j]){
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};