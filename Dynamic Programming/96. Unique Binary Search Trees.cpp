/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n? */

/* Analysis: Dp problem,
 * let denote dp[n] is the number of unique BST from [1,..,n] length = n
 * root can be 1 to n, then divide the length to two parts!
 * dp[n] : root = 1  1       *  dp[n-1]
 *         root = 2  dp[1]   *  dp[n-2]
 *         root = 3  dp[2]   *  dp[n-3]
 *          ...      ...
 *         root = n  dp[n-1] *  1
 *********/

class Solution {
public:
    int numTrees(int n) {
      if(n == 0) { return 1; }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int len = 2; len <= n; len++) {
          for(int root = 1; root <= len; root++) {
            dp[len] += dp[root-1] * dp[len-root];
          }
        }
        return dp[n];
    }
};


