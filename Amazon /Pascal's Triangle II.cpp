//dp[i]: the vector of ith row;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        dp[0] = {1};
        dp[1] = {1, 1};
        for(int i = 2; i <= rowIndex; i++){
          //dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          dp[i][0] = 1, dp[i][i+1] = 1;
          for(int j = 1; j < i+1; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          }
        }
        return dp[rowIndex];
    }
};