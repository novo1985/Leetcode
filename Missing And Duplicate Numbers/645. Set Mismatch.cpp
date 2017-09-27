
/* our task is to firstly find the number occurs twice and then find the number that is missing.
 * Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]  ********/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      if(nums.empty()) { return {}; }
      //same strategy: put the number to its correct positon by swaping
      vector<int> res(2,0);
      for(int i = 0; i < nums.size(); i++) {
        while(nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
          swap(nums[i], nums[nums[i]-1]);
        }
      }

      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i+1) {
          res[0] = nums[i];
          res[1] = i+1;
        }
      }

      return res;
    }
};