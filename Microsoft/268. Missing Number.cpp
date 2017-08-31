// [0,..,n] total has n+1 numbers, now array: contains n distinc numbers from [0,..,n],
// find the missing number

/* bitwise operation ^: res = nums ^ [0,..,n]*/
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