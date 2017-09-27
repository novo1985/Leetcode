/* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that
 * is missing from the array.

For example,
Given nums = [0, 1, 3] return 2. ******/

/* bit operation */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int res = 0;
      for(int i = 0; i < nums.size(); i++) {
        res ^= nums[i] ^ (i+1);
      }
      return res;
    }
};

/* const space and O(n) time, general solution: two time iteration
 * First Interation: swap, put the number into its right
 * Second iteration: check and find nums[i] != i, return i
 * [0,1,2,3,4,..,n]
 * corn case: case1) if empty, return 0;
 *            case2) if "no missing", return nums.size() ****/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      //corner case1)
      if(nums.empty()) { return 0;}

      //First iteration: put all element into its correct position by swaping
      for(int i = 0; i < nums.size(); i++) {
        while(nums[i] != i && nums[i] != nums[nums[i]]) {
          swap(nums[i], nums[nums[i]]);
        }
      }

      //second iteration: check and find the missing number : nums[i] != i, return i;
      int missing = -1;
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i) {
          missing = i;
        }
      }
      return missing == -1? nums.size() : missing;
    }
};






