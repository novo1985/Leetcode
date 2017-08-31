#include <bits/stdc++.h>
using namespace std;

/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum
 * length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"    ****************/

/* solution: DP, define isPal[i][j] is true if s[i, .. ,j] is palindrome
 * DP 动态方程：
 * isPal[i][j] is true if:
 * 1) s[i] == s[j]
 * 2) isPal[i+1][j-1] is true or i+1) > j-1 (两头的指针相遇了） */

class Solution{
public:
  string longestPalindrome(string s) {
    if(s.size() <= 1){ return s;}
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    int start = 0; //start index of longest Pal
    int maxlen = 1;
    for(int i = 0; i < n; i++){
      isPal[i][i] = true;
      start = i;
      maxlen = 1;
    }
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
        isPal[i][i+1] = true;
        maxlen = 2;
        start = i;
      }
    }

    for(int len = 3; len <= n; len++){//palindrome 可能的长度
      for(int i = 0; i <= n - len; i++){ // 最大的i value ： n-1 - i + 1 = len ==> i = n-len;
        int j = len + i - 1;
        if(s[i] == s[j] && (isPal[i+1][j-1] || i+1 > j-1)){
          isPal[i][j] = true;
          maxlen = len;
          start = i;
        }
      }
    }//遍历结束， 得到最终的maxlen， 和其中一个start
    return s.substr(start, maxlen);
  }
};








