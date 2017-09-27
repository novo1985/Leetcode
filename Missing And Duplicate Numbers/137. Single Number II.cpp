/* Given an array of integers, every element appears three times except for one,
 which appears exactly once. Find that single one.*/

/* 我们可以建立一个32位的数字，来统计每一位上1出现的个数，我们知道如果某一位上为1的话，那么如果该整数出现了三次，
 * 对3去余为0，我们把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int res = 0;
      //create a 32-bit number
      for(int i = 0; i < 32; i++) {
        int sum = 0;
        //for each bit position (start from bit 0th to bit 31th),sum all coordinate nums bit value
        for(int j = 0; j < nums.size(); j++) {
          sum += (nums[j] >> i) & 1 // here bit manipulate "& 1" == & 0000...00001
        }

        res |= sum % 3 << i;//put it back to its position!
      }

      return res;
    }
};






