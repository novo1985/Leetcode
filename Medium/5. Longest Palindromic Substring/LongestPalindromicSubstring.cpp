#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.     ********/

class Solution {
public:
    string longestPalindrome(string s) {
      /* Let defind DP[i][j] be the bool value to check whether s[i,..,j] is palindrome
       * if s[i] == s[j], DP[i][j] = DP[i+1][j-1]
       * else DP[i][j] = false;
       * Base case: DP[i][i] == true;
                    DP[i][i+1] = (s[i] == s[i+1])? true : false     **********/
      if(s.empty()) { return "";}
      bool table[1000][1000] = {false};
      int start_index = 0;
      int max_len = 1
      for(int i = 0; i < s.size(); i++){
        table[i][i] = true;
        start_index = i;
        max_len = 1;
      }

      for(int i = 0; i < size()-1; i++){
        if(s[i] == s[i+1]){
          table[i][i+1] = true;
          start_index = i;
          max_len = 2;
        }
      }

      for(int len = 3; len <= s.size(); len++){
        for(int i = 0; i < s.size()+1-len; i++){
          int j = i + len - 1; // j - i + 1 = len
          if(s[i] == s[j] && table[i+1][j-1]){
            table[i][j] = true;
            start_index = i;
            max_len = len;
          }
        }
      }
      return s.substr(start_index, max_len);
    }
};
