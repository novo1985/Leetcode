#include <bits/stdc++.h>
using namespace std;

/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
 * right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time. ***************************/

// dp[][]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(i == 0 && j == 0) { dp[i][j] = grid[0][0];}
          else if (i == 0 && j > 0) { dp[i][j] = grid[i][j] + dp[i][j-1];}
          else if (i > 0 && j == 0) { dp[i][j] = grid[i][j] + dp[i-1][j];}
          else{
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
          }
         }
      }
      return dp[m-1][n-1];
    }
};

// dp[]???
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<int> dp(n, grid[0][0]);
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(j > 0){
            dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
          }
        }
      }
      return dp[n-1];
    }
}; // wrong





