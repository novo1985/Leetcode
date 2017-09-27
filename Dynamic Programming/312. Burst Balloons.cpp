/* Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented
 * by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get
 * nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After
 * the burst, the left and right then becomes adjacent.
 *
 * Example:

    Given [3, 1, 5, 8]

    Return 167   **************************************************/

/* Dp: Find the first split points which make the sum of two subset maximum
 * Dp(left, right) : the maximum value we can get from array (left, .. ,right)
 *                   where left and right are untouched boundary!
 *
 * dp[i][j]: max { dp[i][k-1] + dp[k+1][j] } for possible choices
 * bound[i][j]? left and right
 * bound[i][k-1] left and nums[k+1]
 * bound[k+1][j] nums[k-1] and right
 * how to organize this bound to related dp ? *****************************/


class Solution {
public:
    int maxCoins(vector<int>& nums) {
      if(nums.empty()) return 0;

      int n = nums.size();
      nums.insert(nums.begin(), 1);
      nums.push_back(1);
      //now the size of nums == n + 2, right = 1 & left = 1;
      vector<vector<int>> dp(n+2, vector<int>(n+2, 0));//dp[1][n] ?

      for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }

      return dp[1][n];
    }
};































