#include <iostream>
#include <string>
using namespace std;
#include <cctype>
/* there is a function called "tolower()"
 * a function called "isalnum()"*/

/* Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.*/

class Solution {
public:
    bool isPalindrome(string s) {
      if(s.empty()) {return true;}
      //two pointers, skip non-alphanumeric, compare s[left] and s[right]
      int left = 0;
      int right = s.size()-1;
      while(left < right){
        if(!isalnum(s[left]))  { left++; continue; }
        if(!isalnum(s[right])) { right--; continue;}

        if(tolower(s[left]) != tolower(s[right])){
          return false;
        }
        else{
          left++;
          right--;
        }
      }
      return true;
    }
};