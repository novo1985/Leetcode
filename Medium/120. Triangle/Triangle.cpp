#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to
 * adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).    ***************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if(triangle.empty()) { return 0; }
      //vector<int> path;
      int n = triangle.size();
      //path.push_back(triangle[0][0]);
      //dp[i][j]: define as , at the i th level, minimum sum ending with triangle[i][j]
      vector<vector<int>> dp(n, vector<int>(n,0));
      dp[0][0] = triangle[0][0];
      for(int i = 1; i < n; i++){
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        dp[i][triangle[i].size()-1] = triangle[i][triangle[i].size()-1] +
                                      dp[i-1][triangle[i-1].size()-1];
        for(int j = 1; j < triangle[i].size()-1; j++){ // special case: j = 0 && j = size()-1
          dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
        }
      }
      int min = INT_MAX;
      for(int k = 0; k < triangle[n-1].size(); k++){
        if(dp[n-1][k] < min){
          min = dp[n-1][k];
        }
      }
      return min;
    }
};

 class Solution {
 public:
      int minimumTotal(vector<vector<int> > &triangle) {
          // IMPORTANT: Please reset any member data you declared, as
          // the same Solution instance will be reused for each test case.
          const int rows = triangle.size();
          int dp[rows];
          for(int i = 0; i < rows; i++)
              dp[i] = triangle[rows-1][i];// bottom_up, initialization
          for(int i = rows-2; i >= 0; i--)
              for(int j = 0; j <= i; j++)
                  dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
          return dp[0];
     }
};









