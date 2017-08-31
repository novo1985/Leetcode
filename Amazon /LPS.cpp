class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /* Typical DP problem, let denote dp[i][j] as the length of longest palindrome subsequence for string [i, .. , j],
         * while(i < j)
         * if s[i] == s[j], then dp[i][j] = 2 + dp[i+1][j-1]
         * else dp[i][j] = max{ dp[i+1][j], dp[i][j-1] } */

        if(s.size() < 2) { return s.size(); }
        int n = s.size();
        int dp[n][n]; // create 2D table
        for(int i = 0; i < n; i++) { dp[i][i] = 1; } //base case, only one char

        //the possible length of LPS can be 2 to n
        for(int len = 2; len <= n; len++){
            for(int i = 0; i<= n - len; i++){// (n-1) - max +1 = len ==> max = n-len;
                //i is one end, j is another end ( j - i + 1 = len  ==> j = len + i - 1)
                int j = len + i -1;
                if(s[i] == s[j] && len == 2) { dp[i][j] = 2; }
                else if (s[i] == s[j]){// len > 2
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else if(s[i] != s[j]){
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};