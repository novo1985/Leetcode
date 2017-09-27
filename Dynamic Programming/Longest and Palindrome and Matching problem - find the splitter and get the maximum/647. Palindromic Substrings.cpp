/*  Given a string, your task is to count how many palindromic substrings in this string. */

/* recursion: if odd, each i as center, expend both side, check ispalin? if yes, sum all of them
 *            if even, each i and i+1 as center
 *****/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) { return 0; }
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
          helper(i, i, s, res);
          helper(i, i+1, s, res);
        }
        return res;
    }

    void helper(int i, int j, string& s, int& res) {
      while(i >= 0 && j <= s.size()) {
        if(s[i] == s[j]){
          res++;
          i--;
          j++;
        }
        else{
          break;
        }
      }
    }
};

/* Dp(i, j) is true, if s[i,..j] is palindrome. if dp(i, j), res++
 * how to determine dp(i, j) is palindrome?
 * if dp(i+1, j-1) is true, then if s[i] == s[j], dp(i, j) is true***/

class Solution {
public:
    int countSubstrings(string s) {
      if(s.empty()) return 0;
      int n = s.size();
      int res = 0;
      vector<vector<bool>> dp(n, vector<bool>(n, false));
      //len = 1;
      for(int i = 0; i < n; i++) { dp[i][i] = true; res++;}

      //len = 2
      for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]) {
          dp[i][i+1] = true;
          res++;
        }
      }
      //len = 3 to n
      for(int len = 3; len = n; len++) {
        for(int i = 0; i < n - len; i++) {
          int j = i + len - 1;
          if(s[i] == s[j] && (dp[i+1][j-1]) || i+1 > j-1){
            dp[i][j] = true;
            res++;
          }
        }
      }

      return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
      if(s.empty()){ return 0;}
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        //int start = 0; //start index of longest Pal
        int count = 0;

        for(int i = 0; i < n; i++){
          isPal[i][i] = true;
          count++;
        }

        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
            isPal[i][i+1] = true;
            count++;
          }
        }

        for(int len = 3; len <= n; len++){//palindrome 可能的长度
          for(int i = 0; i <= n - len; i++){ // 最大的i value ： n-1 - i + 1 = len ==> i = n-len;
            int j = len + i - 1;
            if(s[i] == s[j] && (isPal[i+1][j-1] || i+1 > j-1)){
              isPal[i][j] = true;
              count++;
            }
          }
        }//遍历结束， 得到最终的maxlen， 和其中一个start
        return count;
    }
};





