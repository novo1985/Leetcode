#include <bits/stdc++.h>
using namespace std;

/* Given an array of n integers where n > 1, nums, return an array output such that output[i] is
 * equal to the product of all the elements of nums except nums[i].

 * Solve it **without division** and in O(n).

 * For example, given [1,2,3,4], return [24,12,8,6].
 * Could you solve it with constant space complexity?                    ********************/

//不能用除法！！！
/* element in array can not be zero!!!!
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> res(nums.size(), 0);
      if(nums.empty()) { return res; }
      int product = 1;
      for(int i = 0; i < nums.size(); i++){
        product *= nums[i];
      }
      for(int i =0; i < nums.size(); i++){
        res[i] = product/nums[i];
      }
      return res;
    }
};
*/

/* o(n) but need extra space: res[i] = product[before_i] X product[after_i]  ********/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n, 1);
      vector<int> before_product(n, 1);
      vector<int> after_product(n, 1);
      //before_product[0] = 1! which means before nums[0], the product is "1"!
      int product = 1;
      for(int i = 1; i < n; i++){
        product *= nums[i-1];
        before_product[i] = product;
      }
      //after_product[n-1] = 1! which means after nums[n-1], the product is "1"!
      int product = 1;
      for(int j = n-2; j >= 0; j--){
        product *= nums[j+1];
        after_product[j] = product;
      }
      for(int k = 0; k < n; k++){
        res[k] = before_product[k] * after_product[k];
      }
      return res;
    }
};

/* o(n) and constant space complexity **/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n, 1);
      //temporary res value: from left to right
      for(int i = 1; i < n; i++){
        res[i] = res[i-1] * nums[i-1];
      }
      //update, from right to left
      int right = 1;
      for(int j = n-1; j >= 0; j--){
        res[j] = res[j] * right;
        right = right * num[j];
      }
      return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //第一次遍历， 先得到 res[i] = nums[i]左侧所有元素的乘积, res[0]: nums[0]左侧是空，默认乘积为“1”
        int n = nums.size();
        vector<int> res(n, 1); // 第一次遍历，res 表示nums[i]左侧所有元素的乘积；
        for(int i = 1; i < n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        //第二次遍历， update res[i] = nums[i]左侧所有元素的乘积 * nums[i]右侧所有元素的乘积；
        // nums[i]右侧所有元素的乘积 = right, 从最右侧开始（类似第一次遍历）
        int right = 1;
        for(int j = n-1; j >= 0; j--){//nums[n-1] 右侧为空，right = 1
            res[j] = res[j] * right; // left * right
            right = right * nums[j]; //下一次循环， nums[j-1]右侧所有元素的乘积
        }
        return res;
    }
};





















