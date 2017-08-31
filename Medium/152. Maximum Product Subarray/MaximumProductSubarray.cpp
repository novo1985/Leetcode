#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Find the contiguous subarray within an array (containing at least one number) which has the
 * largest product.

 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6. ********************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      /* maxs[j] = max{A[j], A[j] * maxs[j - 1], A[j] * mins[j - 1]};
       * mins[j] = min{A[j], A[j] * maxs[j - 1], A[j] * mins[j - 1]};   */
      vector<int> max_value(n,0);
      vector<int> min_value(n,0);
      int maxProduct = nums[0];
      max_value[0] = min_value[0] = nums[0];
      for(int i = 1; i<n; i++){
        int temp_up = max_value[i-1] * nums[i];
        int temp_low = min_value[i-1] * nums[i];
        max_value[i] = max(max(nums[i], temp_up), temp_low);
        min_value[i] = min(min(nums[i], temp_up), temp_low);
        maxProduct = max(maxProduct, max_value[i]);
      }
      return maxProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int lower, upper;
      int n = nums.size();
      int maxProduct = nums[0];
      lower = upper = nums[0];

      int tmp1 = 0, tmp2 = 0;
      for (int i =1; i < n; ++i) {
        tmp1 = nums[i] * upper;
        tmp2 = nums[i] * lower;
        upper = max(max(nums[i], tmp1), tmp2);
        lower = min(min(nums[i], tmp1), tmp2);
        maxProduct = max(maxProduct, upper);
      }
      return maxProduct;
    }
};




