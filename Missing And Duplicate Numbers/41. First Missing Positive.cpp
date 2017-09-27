/* Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.*/


/* Thinking: Given an array, size = n, the perfect case is [1,2,3,..,n]
 * Because we need find the first missing positve, when we pass through check each element
 * case1) if nums[i] > n, we can ignore it, the first missing postive must be located [1,..n]
 * case2) if nums[i] < 1, similar logic, we also ignore it
 * case3) if  1 <= nums[i] <= n, we just put it into the correct position! using swap
 *
 * checking step: after all swap operation, pass through the new array, find the first element
 * which nums[i] != i+1, return i+1
 *
 * be caution: corner case, after swap, if the new array is [1,2,3,..n], still need to output
 * the missing number: it should be n+1!!!  ****/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      //corner case: empty array
      if(nums.empty()) { return 1; }

      //first iteration, put the right value into the right position
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > nums.size() || nums[i] < 1) { continue; }
        while(nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
          swap(nums[i], nums[nums[i]-1]);
          if(nums[i] > nums.size() || nums[i] < 1){ // avoid endless loop
            break;
          }
        }
      }

      //second iteration, check the first non-match value
      int first = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i+1){
          first = i+1;
          break;
        }
      }
      //consider the corner case [1,2,3..n], then first = 0 here
      return first == 0? nums.size()+1 : first;
    }
};



