/* Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).

 * The matching should cover the entire input string (not partial).   ****/


/* Thinking: Match problem is similar to Longest Common Sequence
 * *********/
class Solution {
public:
    bool isMatch(string s, string p) {
      if(s.empty() && p.empty()) { return true; }
      int m = s.size(), n = p.size();
      vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
      dp[0][0] = true;
      //one string is empty
      //case1: s is empty
      for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
          dp[0][j] = dp[0][j-1];
        }
      }
      //case2: p is empty
      //for(int i = 1; i <= m; i++) dp[i][0] = false; already initialized

      //both strings are not empty
      for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '*') {
              //match 0 char of s: dp[i][j] = dp[i][j-1];
              //match 1 char of s: dp[i][j] = dp[i-1][j-1];
              //match more than 1 char of s: dp[i][j] = dp[i-1][j]
              //all these three situations need || together
              dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
            }
            if(p[j-1] == '?') {
              dp[i][j] = dp[i-1][j-1];
            }
            else {
              if(p[j-1] == s[i-1]) {
                dp[i][j] = dp[i-1][j-1];
              }
            }
        }
      }

      return dp[m][n];
    }
};