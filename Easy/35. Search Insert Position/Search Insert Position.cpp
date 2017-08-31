#include <iostream>
#include <vector>
using namespace std;

/*Given a sorted array and a target value, return the index if the
target is found. If not, return the index where it would be if it
were inserted in order.*/

class Solution{
public:
    int searchInsert(vector<int>& nums, int target) {
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= target){
          return i;
        }
      }
      return nums.size();
    }
};