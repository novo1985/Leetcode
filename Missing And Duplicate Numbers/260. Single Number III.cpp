/* Given an array of numbers nums, in which exactly two elements appear only once and all the
 * other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].*/


/* 先，对于数组A, 假设存在b，c两个数字，在数组中只出现了一次，那么对于整个数组进行异或操作的话，
 * ^[A]   =  b^c ,  因为其他的数因为出现了两次，异或的过程中就被清零了。
 * 但是仅仅通过最后异或出来的值，是没办法求出b和c的值的，但是足以帮我们把b和c划分到不同的子数组中去。
 * 一个整数有32位bit，对于b和c，除非两者是相同的数，否则一定存在第K位bit，两者是不同的。*/
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        // Pass 1 : get the xor result
        int xor_result = 0;
        for(int i = 0; i < nums.size(); i++) {
          xor_result ^= nums[i];//xor_result = b ^ c
        }

        //find the first bit which value = 1 : (b 0) ^ (c 1) = 1
        int first_one_index = 0;
        for(int i = 0; i < 32; i++) {
          if(xor_result >> i & 1 == 1) {
            first_one_index = i;
            break;
          }
        }

        vector<int> res(2,0);
        //use first_one_index to seperate the original array
        for(const auto& a : nums) {
          if(a >> first_one_index & 1 == 1){
            res[0] ^= a;
          }else {
            res[1] ^= a;
          }
        }

        return res;
    }
};








