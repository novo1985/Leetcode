#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?    **********************/

/* Dp[m][n] define as unique path for m x n grid
 * Dp[i][j] = Dp[i-1][j] + Dp[i][j-1];
 * Dp[1][j] = 1; Dp[i][1] = 1 ***********/
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> Dp(m+1, vector<int>(n+1, 1)); //initialization to 1, define the
                                                        //size[m+1, n+1] to get [m][n]
      for(int i = 2; i < m+1; i++){
        for(int j = 2; j < n-1; j++){
          Dp[i][j] = Dp[i-1][j] + Dp[i][j-1];
        }
      }
      return Dp[m][n];
    }
};

class Solution {
public:
     int uniquePaths(int m, int n) {
         vector<vector<int> > dp(m+1, vector<int>(n+1, 1));
         for(int i = 2; i <= m; i++)
             for(int j = 2; j <= n; j++)
                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
         return dp[m][n];
     }
};









