#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.   *********************************/

/* still using DP,    */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> dp(m, vector<int>(n, 1));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(obstacleGrid[i][j] == 1){ dp[i][j] = 0; }
          else if( i == 0 && j == 0) { dp[i][j] = 1; } // just 1x1 block
          else if( i == 0 && j > 0)  { dp[i][j] = dp[i][j-1]; } // 1 x n block
          else if( i > 0  && j == 0) { dp[i][j] = dp[i-1][j]; } // m x 1 block
          else { dp[i][j] = dp[i-1][j] + dp[i][j-1]; }
        }
      }
     return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
