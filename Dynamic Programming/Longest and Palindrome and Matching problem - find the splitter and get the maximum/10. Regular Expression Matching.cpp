/* Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial). */

/* Thinking: Matching is similar to Longest Common Sequence */
class Solution {
public:
    bool isMatch(string s, string p) {
      int m = s.size(), n = p.size();
      vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
      //two strings ending with i and j: dp[i][j] match or not, including i and j

      //base case1: two empty strings
      dp[0][0] = true;


      //base case2: s is empty
      for(int j = 1; j <= n; j++) {
          dp[0][j] = dp[0][j-2] && (p[j-1] == '*') && (j > 1);
      }

      //base case3: p is empty, false, already initialized

      for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
          if(p[j-1] == '*') {
            //case1: match zero char of s
            //case2: match only one char of s
            //case3: match more than one chars of s
            /*dp[i][j] == dp[i][j-2] || (dp[i-1][j-2] && (s[i-1] == p[j-2]|| p[j-2] == '.')) ||
                      (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));*/
            dp[i][j] == dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
          }
          if(p[j-1] == '.'){
            dp[i][j] = dp[i-1][j-1];
          }
          else{
            dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
          }
        }
      }

      return dp[m][n];
    }
};


(s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];







