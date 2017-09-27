/* You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.   ****************/


/* let denote dp[i]: minimum number of coins which sum to i;
 * Base case: if i == 0, dp[0] = 0;
 *            if i > 0,  dp[i] = min(dp[i], 1 + dp[i - coins[j]])
 *            where i ranges from [0, coins.size()-1] & coins[j] <= i ******/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if(amount <= 0) { return 0; }

      vector<int> dp(amount+1, INT_MAX);
      dp[0] = 0;

      for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
          if(coins[j] <= i) {
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
          }
        }
      }

      return dp[amount] == INT_MAX? -1; dp[amount];
    }
};


















