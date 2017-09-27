/* Given a string S and a string T, count the number of distinct subsequences of S which equals T. */

/* Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. */


/* it is similar to longest common sequence:
 * count(i, j) denote as S[0,..,i] & T[0,..j] the number of distinct subsequences
 * count(i, j) = count(i-1, j-1) + count(i-1, j), ifs[i] == t[j]
 *             = count(i-1, j) else if
 * Base case: 1) if j < 0 count[i, j] = 1
 *            2) if i < 0, j >= 0 count[i, j] = 0
 *            3) if i = 0 & j = 0 & s[i] = t[j] count(i, j) = 1
 *            4) if i = 0 & j = 0 & s[i] != t[j] count(i, j) = 0      ******/

class Solution {
public:
    int numDistinct(string s, string t) {
      int m = s.size(), n = t.size();
      vector<vector<int>> cnt(m+1, vector<int>(n+1, 0));

      //base case: initialization
      for(int i = 0; i <= m; i++) {
        cnt[i][0] = 1;//string t is empty
      }
      for(int j = 1; j <= n; j++) {
        cnt[0][j] = 0;//string s is empty
      }
      //if(s[1] == t[1]) { cnt[1][1] = 1; }

      for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
          if(s[i-1] == t[j-1]) {
            cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j];
          }else{
            cnt[i][j] = cnt[i-1][j];
          }
        }
      }

      return cnt[m][n];
    }
};






