#include <bits/stdc++.h>
using namespace std;

/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3    ******************/

/* dp[0] = 1
 * dp[1] = 1
 * 左右两侧的长度！！！
 * [1,2]: 以1为root & 以2为root, dp[2] = dp[1]*dp[0] + dp[1]dp[0]
 * [1,2,3]: 以1为root & 以2为root & 以3为root, dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[0]dp[2];
 * [1,2,3,4]: 以1为root & 以2为root & 以3为root & 以4为root,
 *            dp[4] = dp[0]*dp[3] + dp[1]*dp[2] + dp[2]*dp[1] + dp[3]dp[0];
 *[1,2,3,..,n]: 以1为root & 以2为root & 以3为root & ... 以n为root,
 *            dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + ... + dp[n-1]*dp[0]
              <==> dp[n] = ∑dp[k][n-1-k] (0 <= k <= n-1)
 *******************/

class Solution {
public:
    int numTrees(int n) {
      vector<int> dp(n+1, 0);
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
          dp[i] += dp[j]*dp[i-1-j];
        }
      }
      return dp[n];
    }
};















